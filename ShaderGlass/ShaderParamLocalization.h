/*
ShaderGlass: shader effect overlay
Copyright (C) 2021-2026 mausimus (mausimus.net)
GNU General Public License v3.0
*/

#pragma once

#include <string>
#include <string_view>
#include <unordered_map>

inline std::wstring LocalizeShaderParam(std::wstring_view description)
{
    // Match full phrases first, then individual words. Preserve shader names,
    // numeric ranges, abbreviations and any terminology missing from the glossary.
    static const std::unordered_map<std::wstring_view, std::wstring_view> glossary = {
        {L"aspect ratio", L"宽高比"}, {L"black level", L"黑电平"}, {L"white point", L"白点"},
        {L"color temperature", L"色温"}, {L"color space", L"色彩空间"}, {L"color bleed", L"串色"},
        {L"mask strength", L"遮罩强度"}, {L"scanline strength", L"扫描线强度"},
        {L"beam width", L"电子束宽度"}, {L"input gamma", L"输入伽马"}, {L"output gamma", L"输出伽马"},
        {L"monitor gamma", L"显示器伽马"}, {L"target gamma", L"目标伽马"},
        {L"brightness boost", L"亮度增强"}, {L"gamma boost", L"伽马增强"},
        {L"red channel", L"红色通道"}, {L"green channel", L"绿色通道"}, {L"blue channel", L"蓝色通道"},
        {L"black frame", L"黑帧"}, {L"anti-aliasing", L"抗锯齿"}, {L"integer scale", L"整数缩放"},
        {L"barrel distortion", L"桶形畸变"}, {L"curvature radius", L"曲率半径"},
        {L"shadow mask", L"荫罩"}, {L"slot mask", L"槽形遮罩"}, {L"aperture grille", L"孔栅"},
        {L"frame rate", L"帧率"}, {L"refresh rate", L"刷新率"}, {L"pixel size", L"像素大小"},
        {L"back color", L"背景色"}, {L"backlight", L"背光"},
        {L"scanline", L"扫描线"}, {L"scanlines", L"扫描线"}, {L"mask", L"遮罩"},
        {L"strength", L"强度"}, {L"color", L"色彩"}, {L"colors", L"色彩"}, {L"colour", L"色彩"},
        {L"gamma", L"伽马"}, {L"on", L"开"}, {L"off", L"关"}, {L"offset", L"偏移"},
        {L"scale", L"缩放"}, {L"scaling", L"缩放"}, {L"vertical", L"垂直"}, {L"vert", L"垂直"},
        {L"horizontal", L"水平"}, {L"horiz", L"水平"}, {L"red", L"红色"}, {L"green", L"绿色"}, {L"blue", L"蓝色"},
        {L"mode", L"模式"}, {L"screen", L"屏幕"}, {L"sharpness", L"锐度"}, {L"size", L"大小"},
        {L"glow", L"辉光"}, {L"width", L"宽度"}, {L"height", L"高度"}, {L"brightness", L"亮度"},
        {L"bright", L"亮部"}, {L"brighten", L"提亮"}, {L"bloom", L"泛光"},
        {L"amount", L"程度"}, {L"amt", L"程度"}, {L"toggle", L"开关"}, {L"curvature", L"曲率"},
        {L"noise", L"噪声"}, {L"resolution", L"分辨率"}, {L"res", L"分辨率"},
        {L"beam", L"电子束"}, {L"blur", L"模糊"}, {L"image", L"图像"}, {L"img", L"图像"},
        {L"type", L"类型"}, {L"threshold", L"阈值"}, {L"boost", L"增强"}, {L"border", L"边框"},
        {L"enable", L"启用"}, {L"disable", L"禁用"}, {L"shift", L"偏移"}, {L"signal", L"信号"},
        {L"overscan", L"过扫描"}, {L"phase", L"相位"}, {L"auto", L"自动"}, {L"filter", L"滤镜"},
        {L"intensity", L"强度"}, {L"max", L"最大"}, {L"maximum", L"最大"}, {L"min", L"最小"},
        {L"minimum", L"最小"}, {L"radius", L"半径"}, {L"zoom", L"缩放"}, {L"corner", L"边角"},
        {L"chroma", L"色度"}, {L"chromatic", L"色彩"}, {L"black", L"黑色"}, {L"aspect", L"宽高比"},
        {L"bezel", L"边框"}, {L"full", L"完整"}, {L"correction", L"校正"}, {L"tint", L"色调"},
        {L"blend", L"混合"}, {L"use", L"使用"}, {L"ringing", L"振铃"}, {L"center", L"中心"},
        {L"luma", L"亮度"}, {L"luminance", L"亮度"}, {L"dark", L"暗部"}, {L"phosphor", L"荧光粉"},
        {L"tilt", L"倾斜"}, {L"pixel", L"像素"}, {L"pixels", L"像素"}, {L"edge", L"边缘"}, {L"edges", L"边缘"},
        {L"saturation", L"饱和度"}, {L"tube", L"显像管"}, {L"shadow", L"阴影"}, {L"crop", L"裁剪"},
        {L"multiplier", L"倍率"}, {L"axis", L"轴"}, {L"convergence", L"会聚"}, {L"deconvergence", L"会聚偏差"},
        {L"only", L"仅"}, {L"shape", L"形状"}, {L"integer", L"整数"}, {L"composite", L"复合"},
        {L"sigma", L"标准差"}, {L"slot", L"槽"}, {L"ratio", L"比例"}, {L"vignette", L"暗角"},
        {L"reflection", L"反射"}, {L"refl", L"反射"}, {L"halation", L"光晕"}, {L"geom", L"几何"},
        {L"range", L"范围"}, {L"flare", L"眩光"}, {L"high", L"高"}, {L"hi", L"高"},
        {L"none", L"无"}, {L"cutoff", L"截止"}, {L"sharp", L"锐利"}, {L"level", L"级别"},
        {L"low", L"低"}, {L"mid", L"中"}, {L"hue", L"色相"}, {L"white", L"白色"},
        {L"contrast", L"对比度"}, {L"position", L"位置"}, {L"pos", L"位置"}, {L"power", L"幂"},
        {L"distance", L"距离"}, {L"subpixel", L"子像素"}, {L"frame", L"帧"}, {L"speed", L"速度"},
        {L"lines", L"线条"}, {L"line", L"线条"}, {L"opacity", L"不透明度"}, {L"weight", L"权重"},
        {L"custom", L"自定义"}, {L"gain", L"增益"}, {L"input", L"输入"}, {L"output", L"输出"},
        {L"interlacing", L"隔行扫描"}, {L"interlace", L"隔行扫描"}, {L"left", L"左"}, {L"right", L"右"},
        {L"effect", L"效果"}, {L"inner", L"内侧"}, {L"outer", L"外侧"}, {L"smoothness", L"平滑度"},
        {L"smooth", L"平滑"}, {L"display", L"显示"}, {L"adjust", L"调整"}, {L"adjustment", L"调整"},
        {L"layer", L"图层"}, {L"thickness", L"厚度"}, {L"dot", L"点"}, {L"show", L"显示"},
        {L"default", L"默认"}, {L"def", L"默认"}, {L"add", L"添加"}, {L"ambient", L"环境"},
        {L"bg", L"背景"}, {L"background", L"背景"}, {L"value", L"值"}, {L"mod", L"调制"},
        {L"demod", L"解调"}, {L"channel", L"通道"}, {L"light", L"光照"}, {L"grid", L"网格"},
        {L"persistence", L"余辉"}, {L"mitigate", L"抑制"}, {L"smart", L"智能"}, {L"frequency", L"频率"},
        {L"freq", L"频率"}, {L"palette", L"调色板"}, {L"top", L"顶部"}, {L"bottom", L"底部"},
        {L"split", L"分割"}, {L"grain", L"颗粒"}, {L"radial", L"径向"}, {L"viewport", L"视口"},
        {L"lens", L"镜头"}, {L"flip", L"翻转"}, {L"angle", L"角度"}, {L"sharpen", L"锐化"},
        {L"follow", L"跟随"}, {L"gaussian", L"高斯"}, {L"artifacts", L"伪影"}, {L"core", L"核心"},
        {L"factor", L"系数"}, {L"smoothing", L"平滑"}, {L"monitor", L"显示器"}, {L"fade", L"淡化"},
        {L"triad", L"三色组"}, {L"hack", L"兼容修正"}, {L"flicker", L"闪烁"}, {L"less", L"较少"},
        {L"view", L"视图"}, {L"curve", L"曲线"}, {L"dynamic", L"动态"}, {L"static", L"静态"},
        {L"linear", L"线性"}, {L"normal", L"常规"}, {L"errors", L"误差"}, {L"bandwidth", L"带宽"},
        {L"geometry", L"几何"}, {L"distortion", L"畸变"}, {L"texture", L"纹理"}, {L"sample", L"采样"},
        {L"sampling", L"采样"}, {L"mix", L"混合"}, {L"overdrive", L"过驱动"}, {L"rotation", L"旋转"},
        {L"detection", L"检测"}, {L"non-linearity", L"非线性"}, {L"dimming", L"调暗"},
        {L"voltage", L"电压"}, {L"voltages", L"电压"}, {L"separation", L"间距"},
        {L"transparency", L"透明度"}, {L"alpha", L"透明度"}, {L"alignment", L"对齐"}, {L"balance", L"平衡"},
        {L"pattern", L"图案"}, {L"softness", L"柔和度"}, {L"target", L"目标"}, {L"source", L"来源"},
        {L"length", L"长度"}, {L"band", L"频段"}, {L"eq", L"均衡"}, {L"neutral", L"中性"},
        {L"adaptive", L"自适应"}, {L"debug", L"调试"}, {L"advanced", L"高级"}, {L"depth", L"深度"},
        {L"contrast boost", L"对比度增强"}, {L"luma gain", L"亮度增益"}, {L"chroma gain", L"色度增益"},
        {L"tv knob settings", L"电视旋钮设置"},
        {L"artifact settings", L"伪影设置"},
        {L"test patterns", L"测试图案"},
        {L"analog controls", L"模拟控制"},
        {L"digital controls", L"数字控制"},
        {L"sega fixes", L"世嘉兼容修正"},
        {L"analog service menu start", L"模拟维修菜单开始"},
        {L"analog service menu end", L"模拟维修菜单结束"},
        {L"lcd response time", L"LCD 响应时间"},
        {L"crt profile", L"CRT 配置"},
        {L"chrominance", L"色度"},
        {L"aberration", L"色差"},
        {L"amplitude", L"振幅"},
        {L"spacing", L"间距"},
        {L"automatic prescale", L"自动预缩放"},
        {L"prescale", L"预缩放"},
        {L"sensitivity", L"灵敏度"},
        {L"modulation", L"调制"},
        {L"adaptation", L"自适应"},
        {L"accumulate", L"累积"},
        {L"interlaced", L"隔行扫描"},
        {L"ceil", L"向上取整"},
        {L"retention", L"残影"},
        {L"workaround", L"补偿"},
        {L"cadence", L"间隔"},
        {L"frames", L"帧"},
        {L"focused area", L"焦点区域"},
        {L"steepness", L"陡度"},
        {L"staggering", L"交错"},
        {L"blending", L"混合"},
        {L"noblend", L"无混合"},
        {L"diameter", L"直径"},
        {L"inside", L"内侧"},
        {L"outside", L"外侧"},
        {L"bead", L"珠点"},
        {L"bicubic", L"双三次"},
        {L"coeff", L"系数"},
        {L"bleed", L"串色"},
        {L"stretch", L"拉伸"},
        {L"bloomintensity", L"泛光强度"},
        {L"brightboost", L"亮度增强"},
        {L"colorize", L"着色"},
        {L"colorspace", L"色彩空间"},
        {L"darken", L"变暗"},
        {L"colours", L"色彩"},
        {L"iteration", L"迭代"},
        {L"iterations", L"迭代次数"},
        {L"deband", L"去色带"},
        {L"deblur", L"去模糊"},
        {L"deflicker", L"去闪烁"},
        {L"emphasis", L"强调"},
        {L"details", L"细节"},
        {L"sharpened", L"锐化"},
        {L"diffusion", L"扩散"},
        {L"dilation", L"膨胀"},
        {L"erosion", L"腐蚀"},
        {L"dithering", L"抖动"},
        {L"animation", L"动画"},
        {L"dullness", L"灰暗度"},
        {L"vibrance", L"自然饱和度"},
        {L"exposure", L"曝光"},
        {L"extend", L"延伸"},
        {L"horizontally", L"水平方向"},
        {L"vertically", L"垂直方向"},
        {L"fill", L"填充"},
        {L"film scratches", L"胶片划痕"},
        {L"fisheye", L"鱼眼"},
        {L"bend", L"弯曲"},
        {L"force", L"强制"},
        {L"bilinear", L"双线性"},
        {L"filtering", L"滤波"},
        {L"fringing", L"彩边"},
        {L"prevention", L"防止"},
        {L"monochrome", L"单色"},
        {L"analysis", L"分析"},
        {L"gamut", L"色域"},
        {L"compression", L"压缩"},
        {L"jailbars", L"竖条纹"},
        {L"severity", L"程度"},
        {L"ghost", L"重影"},
        {L"ghosting", L"重影"},
        {L"cycles", L"周期"},
        {L"delay", L"延迟"},
        {L"spread", L"扩散"},
        {L"visibility", L"可见度"},
        {L"godray", L"光束"},
        {L"decay", L"衰减"},
        {L"density", L"密度"},
        {L"samples", L"采样数"},
        {L"pin cushion", L"枕形畸变"},
        {L"interference", L"干扰"},
        {L"interpolate", L"插值"},
        {L"selector", L"选择"},
        {L"latency", L"延迟"},
        {L"placement", L"位置"},
        {L"middle", L"中间"},
        {L"checkerboard", L"棋盘格"},
        {L"thresh", L"阈值"},
        {L"treshold", L"阈值"},
        {L"highlight", L"高光"},
        {L"merge fields", L"合并场"},
        {L"mirror wrap", L"镜像环绕"},
        {L"modulator", L"调制器"},
        {L"standard", L"标准"},
        {L"formula", L"公式"},
        {L"neighbor", L"相邻像素"},
        {L"original", L"原始"},
        {L"over scan", L"过扫描"},
        {L"pan", L"平移"},
        {L"variation", L"变化"},
        {L"rolloff", L"滚降"},
        {L"rotate", L"旋转"},
        {L"sharper", L"更锐利"},
        {L"subpixels", L"子像素"},
        {L"scene change", L"场景切换"},
        {L"continuous", L"连续"},
        {L"cropping", L"裁剪"},
        {L"shading", L"着色"},
        {L"levels", L"级别"},
        {L"shadowmask", L"荫罩"},
        {L"shake", L"抖动"},
        {L"shutter", L"快门"},
        {L"swap eyes", L"交换左右眼"},
        {L"eye sequence", L"左右眼顺序"},
        {L"swap", L"交换"},
        {L"param", L"参数"},
        {L"slowness", L"缓慢程度"},
        {L"solo", L"独显"},
        {L"straight", L"直线"},
        {L"taps", L"采样点"},
        {L"tune", L"调整"},
        {L"cam", L"镜头"},
        {L"variance", L"方差"},
        {L"warp", L"扭曲"},
        {L"whitepoint", L"白点"},
        {L"widen", L"加宽"},
        {L"wiggle", L"摆动"},
        {L"window", L"窗口"},
        {L"modifier", L"修正"},
        {L"system specific", L"系统专用"},
        {L"tweaks", L"微调"},
        {L"search steps", L"搜索步数"},
        {L"blurgain", L"模糊增益"},
        {L"blurradius", L"模糊半径"},
        {L"hardpix", L"像素锐度"},
        {L"hardscan", L"扫描线锐度"},
        {L"maskdark", L"遮罩暗部"},
        {L"masklight", L"遮罩亮部"},
        {L"deviation", L"偏差"},
        {L"rgbextragain", L"RGB 额外增益"},
        {L"scaleinlineargamma", L"在线性伽马空间缩放"},
        {L"scanlinegain", L"扫描线增益"},
        {L"warpx", L"X 轴扭曲"},
        {L"warpy", L"Y 轴扭曲"},
    };

    const auto isLetter = [](wchar_t c) { return (c >= L'a' && c <= L'z') || (c >= L'A' && c <= L'Z'); };
    std::wstring lower(description);
    for(auto& ch : lower)
        if(ch >= L'A' && ch <= L'Z')
            ch += L'a' - L'A';

    if(const auto exact = glossary.find(lower); exact != glossary.end())
        return std::wstring(exact->second);

    std::wstring result;
    size_t start = 0;
    while(start < description.size())
    {
        if(!isLetter(description[start]))
        {
            result += description[start++];
            continue;
        }

        size_t end = lower.find_first_not_of(L"abcdefghijklmnopqrstuvwxyz", start);
        if(end == std::wstring::npos)
            end = lower.size();

        auto matchEnd = end;
        auto match = glossary.find(std::wstring_view(lower).substr(start, end - start));
        // Full labels are handled above; try two-word phrases within longer labels.
        if(end + 1 < lower.size() && (lower[end] == L' ' || lower[end] == L'-') && isLetter(lower[end + 1]))
        {
            auto phraseEnd = lower.find_first_not_of(L"abcdefghijklmnopqrstuvwxyz", end + 1);
            if(phraseEnd == std::wstring::npos)
                phraseEnd = lower.size();
            auto phrase = glossary.find(std::wstring_view(lower).substr(start, phraseEnd - start));
            if(phrase != glossary.end())
            {
                match = phrase;
                matchEnd = phraseEnd;
            }
        }

        if(match == glossary.end())
            result.append(description.substr(start, matchEnd - start));
        else
            result.append(match->second);
        start = matchEnd;
    }
    return result;
}
