"""Launch the compiled executable and inspect its live Win32 UI."""
import ctypes as c
from ctypes import wintypes as w
from pathlib import Path
import re
import subprocess
import sys
import time

user = c.WinDLL("user32", use_last_error=True)


def bind(name, result, *args):
    function = getattr(user, name)
    function.restype = result
    function.argtypes = args
    return function


find_window = bind("FindWindowW", w.HWND, w.LPCWSTR, w.LPCWSTR)
get_menu = bind("GetMenu", w.HMENU, w.HWND)
get_submenu = bind("GetSubMenu", w.HMENU, w.HMENU, c.c_int)
get_menu_count = bind("GetMenuItemCount", c.c_int, w.HMENU)
get_menu_text = bind("GetMenuStringW", c.c_int, w.HMENU, w.UINT, w.LPWSTR, c.c_int, w.UINT)
post_message = bind("PostMessageW", w.BOOL, w.HWND, w.UINT, w.WPARAM, w.LPARAM)
visible = bind("IsWindowVisible", w.BOOL, w.HWND)
send_message = bind("SendMessageW", w.LPARAM, w.HWND, w.UINT, w.WPARAM, w.LPARAM)
window_text = bind("GetWindowTextW", c.c_int, w.HWND, w.LPWSTR, c.c_int)
child_callback = c.WINFUNCTYPE(w.BOOL, w.HWND, w.LPARAM)
enum_children = bind("EnumChildWindows", w.BOOL, w.HWND, child_callback, w.LPARAM)


def menu_items(menu):
    result = []
    for index in range(get_menu_count(menu)):
        text = c.create_unicode_buffer(256)
        get_menu_text(menu, index, text, len(text), 0x400)  # MF_BYPOSITION
        result.append((text.value.split("\t")[0].replace("&", ""), get_submenu(menu, index)))
    return result


def controls(window):
    labels = []

    @child_callback
    def collect(child, _):
        text = c.create_unicode_buffer(256)
        send_message(child, 0x000D, len(text), c.addressof(text))  # WM_GETTEXT
        if text.value:
            labels.append(text.value)
        return True

    enum_children(window, collect, 0)
    return labels


def require_labels(expected, actual):
    for label in expected:
        assert any(word.startswith(label) for word in actual), (label, actual)


def wait_for(find, process):
    for _ in range(150):
        if process.poll() is not None:
            raise RuntimeError(f"ShaderGlass exited with {process.returncode}")
        result = find()
        if result:
            return result
        time.sleep(0.2)
    raise TimeoutError("Expected ShaderGlass window did not appear")


resource = Path("ShaderGlass/resource.h").read_text(encoding="utf-8")


def open_window(command, class_name, main, process):
    identifier = int(re.search(rf"^#define\s+{command}\s+(\d+)", resource, re.M)[1])
    assert post_message(main, 0x0111, identifier, 0)  # WM_COMMAND
    return wait_for(lambda: (hwnd := find_window(class_name, None)) and visible(hwnd) and hwnd, process)


exe = Path(sys.argv[1]).resolve()
with subprocess.Popen([str(exe), "-paused"], cwd=exe.parent) as process:
    try:
        # CreateWindow exposes the resource menu before ShaderWindow builds its
        # dynamic submenus. The browser is created after that initialization.
        wait_for(lambda: find_window("SHADERBROWSER", None), process)
        main = wait_for(lambda: (hwnd := find_window("SHADERGLASS", None)) and get_menu(hwnd) and hwnd, process)
        sections = dict(menu_items(get_menu(main)))
        require_labels(["处理", "输入", "输出", "着色器", "帮助"], sections)
        input_menu = dict(menu_items(sections["输入"]))
        require_labels(["桌面", "窗口", "设备", "像素大小"], input_menu)
        require_labels(["锁定当前区域"], dict(menu_items(input_menu["桌面"])))
        require_labels(["下一个", "上一个", "按 DPI 缩放调整", "×1"], dict(menu_items(input_menu["像素大小"])))
        require_labels(["截屏", "全屏", "宽高比校正"], dict(menu_items(sections["输出"])))
        require_labels(["暂停/继续", "显示/隐藏菜单"], dict(menu_items(sections["处理"])))
        require_labels(["参数", "启用"], dict(menu_items(sections["着色器"])))

        browser = open_window("ID_SHADER_BROWSE", "SHADERBROWSER", main, process)
        require_labels(["搜索：", "清空", "添加收藏", "取消收藏", "参数", "像素大小"], controls(browser))
        params = open_window("IDM_SHADER_PARAMETERS", "SHADERPARAMS", main, process)
        title = c.create_unicode_buffer(256)
        window_text(params, title, len(title))
        require_labels(["着色器参数"], [title.value])
        require_labels(["关闭"], controls(params))
        print("Verified Chinese labels in live menus, shader browser, and parameter window")
    finally:
        process.terminate()
