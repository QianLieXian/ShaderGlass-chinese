![License](https://img.shields.io/github/license/mausimus/ShaderGlass?color=red) ![GitHub Stars](https://img.shields.io/github/stars/mausimus/ShaderGlass?color=yellow) ![Downloads](https://img.shields.io/github/downloads/mausimus/ShaderGlass/total) ![Latest Release](https://img.shields.io/github/release-date/mausimus/ShaderGlass?label=latest%20release&color=blue) ![Beta Release](https://img.shields.io/github/release-date-pre/mausimus/ShaderGlass?label=beta%20release&color=orange)

## ShaderGlass

在 Windows 桌面和 Wine 上叠加 GPU 着色器效果的覆盖层工具。

### 功能特性

* 在桌面、浮动窗口或全屏模式下应用着色器效果
* 内置 [RetroArch](https://github.com/libretro/RetroArch) 着色器库（1200+ 着色器！）涵盖：
  * CRT 显示器模拟
  * 图像放大
  * 电视、VHS 和掌机模拟
  * 柔化、降噪、模糊、锐化等更多效果
* 兼容大多数模拟器、复古平台和像素艺术编辑器，包括：
  * [DOSBox](https://www.dosbox.com/)、[FS-UAE](https://github.com/FrodeSolheim/fs-uae)、[Altirra](http://www.virtualdub.org/altirra.html)、
  [ScummVM](https://github.com/scummvm/scummvm)、[AGS](https://github.com/adventuregamestudio/ags)、[VICE](https://sf.net/projects/vice-emu)、[Aseprite](https://www.aseprite.org/) 等
* 像素艺术的绝佳伴侣，可显示着色和/或宽高比校正后的预览
* 甚至可以叠加在 YouTube、Twitch 或现代游戏之上
* 支持从 USB 源（网络摄像头或采集卡）捕获
* 保存和加载配置文件
* 导入外部 .slangp/.slang 着色器
* 高度可定制，提供多种选项、操作模式和着色器参数
* 可被 OBS 捕获（使用游戏捕获源）

查看 [在线手册](https://mausimus.github.io/ShaderGlass/MANUAL.html) 了解更多详情。

<br/>

### 下载

最新稳定版 (v1.3.0, 2026年3月19日)：
* Linux/Wine 下的桌面/窗口捕获
* 着色器搜索功能
* 着色器库更新
* 小幅改进

[https://github.com/mausimus/ShaderGlass/releases/download/v1.3.0/ShaderGlass-1.3.0.win-x64.zip](https://github.com/mausimus/ShaderGlass/releases/download/v1.3.0/ShaderGlass-1.3.0-win-x64.zip)

[测试版和旧版本可在此获取](https://github.com/mausimus/ShaderGlass/releases)

<br/>

[![请我喝杯咖啡！](images/ko-fi.png)](https://ko-fi.com/mausimus)

<br/>

### 在 Steam 上获取！

[![ShaderGlass on Steam](images/steam.png)](https://store.steampowered.com/app/3613770/ShaderGlass/)

<br/>

黑帧插入 (BFI) 和 Blur Busters 的 CRT 光束模拟器已独立为
新应用 [ShaderBeam](https://github.com/mausimus/ShaderBeam)。

<br/>

### 系统要求

* __Windows 10 2004 版本__ (build 19041) 或 __Windows 11__
  * 1903 版本也可运行，但功能受限（无桌面玻璃模式）
  * Windows 11 支持 __移除黄色边框__（参见 [FAQ](FAQ.md#windows-10) 了解在 Windows 10 上避免此问题的技巧）
* 支持 DirectX 11 的 GPU
* __Linux__：自 1.3 版本起支持在 Wine/Proton 下运行，使用 ScreenCast/PipeWire 进行捕获（仅克隆模式）

<br/>

### 演示视频

点击在 YouTube 上观看

[![ShaderGlass (YouTube)](https://img.youtube.com/vi/gWOcucS9_mg/maxresdefault.jpg)](https://www.youtube.com/watch?v=gWOcucS9_mg)

### 截图

ShaderGlass 在 Windows 11 桌面上覆盖多个应用程序运行。

![screenshot](images/screen7.png)

#### 桌面玻璃模式

在此模式下，透明浮动窗口会将着色器效果应用于其后的所有内容。
需要 Windows 10 2004 - 在 1903/1909 上切换到此模式只会看到黑色窗口。

Chrome 中的 Wikipedia 经 crt-geom 着色器处理，应用了扫描线和 CRT 曲面效果。

![screenshot](images/screen1.png)

#### 窗口克隆模式

当捕获固定到特定窗口时，更容易调整缩放以匹配输入，
图像也可以被重新捕获（截图/OBS 等）。

##### FS-UAE

[猴岛的秘密 (1990)](https://store.steampowered.com/app/32360/The_Secret_of_Monkey_Island_Special_Edition/) 的 Amiga 版本
在 FS-UAE 中运行，应用了 crt-interlaced-halation 着色器。

![screenshot](images/screen4.png)

##### Altirra

Atari XL 的 [Ninja (1986)](https://www.mobygames.com/game/ninja_)
在 Altirra 中运行，使用 TV-OUT 模拟着色器。

![screenshot](images/screen5.png)

##### Adventure Game Studio

[The Crimson Diamond (2024)](https://store.steampowered.com/app/1098770/The_Crimson_Diamond/)，
一款使用 HSM MegaBezel STD 着色器的现代 AGS 游戏。

![screenshot](images/screen3.png)

##### DOSBox

[Police Quest (1987)](https://store.steampowered.com/app/494740/Police_Quest_Collection/)
巨大的半 EGA 像素经宽高比校正后，使用 newpixie-crt 着色器进行后处理。

![screenshot](images/screen2.png)

[Rick Dangerous (1989)](https://www.mobygames.com/game/rick-dangerous)
应用了 C64 显示器着色器。

![screenshot](images/screen6.png)

<br/>

### 使用说明和手册

参见 [在线手册](https://mausimus.github.io/ShaderGlass/MANUAL.html) 了解选项说明和常见问题解答。

<br/>

### 代码

使用 Visual Studio 2022 构建，采用 ISO C++ 20 标准、Windows SDK 10.0.26100、Windows Capture API 和 DirectX 11。

ShaderGlass 包含 RetroArch 着色器后端的有限实现，使用 DirectX 11。
[ShaderGen](ShaderGen) 是一个命令行工具，用于将 Slang 着色器转换为
可在 ShaderGlass 中预编译的 .h 文件。转换过程依赖：
1. [glslang](https://github.com/KhronosGroup/glslang) - 将 Slang/GLSL 着色器转换为 SPIR-V
2. [SPIR-V 交叉编译器](https://github.com/KhronosGroup/SPIRV-Cross) - 将 SPIR-V 转换为 HLSL（DX11 格式）
3. [Direct3D 着色器编译器 (fxc.exe)](https://developer.microsoft.com/en-us/windows/downloads/windows-10-sdk/) - 预编译为字节码

<br/>

### 声明

* ShaderGlass 应用程序基于 [GNU 通用公共许可证 v3.0](LICENSE) 提供

* 包含来自 [libretro/RetroArch 着色器仓库](https://github.com/libretro/slang-shaders) 的预编译着色器。
请参阅着色器代码中的版权声明，了解每个着色器的详细版权和许可证信息。

* 应用图标由 Icons-Land 提供

* 向 RetroArch 团队、模拟器开发者和广大的复古社区致敬！

* 感谢 @lonestarr 和 @EndlesslyFlowering 的 PR，以及所有人的反馈和测试 :thumbsup:
