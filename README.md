# WS2812 LED 控制库

## 概述

本项目提供了一个用于控制 WS2812 LED 灯条的库，适用于 ESP32 微控制器。该库包含了多种效果，如呼吸、渐变、闪烁和彩虹效果，以及基本的开关功能。设计时考虑了模块化和易集成性，方便在其他项目中使用。

## 功能特性

- **HSV 到 RGB 转换**：提供了一个辅助函数，用于将 HSV 颜色空间转换为 RGB 颜色空间。
- **多种 LED 效果**：支持常亮、关闭、呼吸、渐入、慢闪、快闪和彩虹效果。
- **单个 LED 控制**：可以单独设置某个 LED 的颜色。
- **颜色宏定义**：预定义了多种常用颜色，如白色、绿色、红色、蓝色等。
- **模块化设计**：代码结构清晰，易于扩展和维护。

## 使用方法

### 1. 创建 WS2812 控制句柄

首先，需要创建一个 WS2812 控制句柄，用于后续的 LED 控制操作。

```c
led_strip_t* strip = ws2812_create();
```

### 2. 设置 LED 效果

可以通过调用 `ws2812_set` 函数来设置 LED 的效果。例如，设置所有 LED 为常亮状态，颜色为红色：

```c
led_color_t color = COLOR_RED;
led_effect_t effect = LED_EFFECT_ON;
ws2812_set(strip, color, effect);
```

### 3. 其他功能

- **设置单个 LED 颜色**：

  ```c
  set_led_color(strip, 0, COLOR_GREEN); // 设置第0个LED为绿色
  ```

- **关闭所有 LED**：

  ```c
  led_set_off(strip);
  ```

- **呼吸效果**：

  ```c
  led_set_breath(strip, COLOR_BLUE);
  ```

- **彩虹效果**：

  ```c
  led_set_rainbow(strip);
  ```

## 示例代码

以下是一个简单的示例代码，展示了如何使用该库控制 WS2812 LED 灯条：

```c
#include "ws2812_control.h"

void app_main() {
    led_strip_t* strip = ws2812_create();

    // 设置所有 LED 为常亮状态，颜色为红色
    led_color_t color = COLOR_RED;
    led_effect_t effect = LED_EFFECT_ON;
    ws2812_set(strip, color, effect);

    // 等待一段时间
    vTaskDelay(pdMS_TO_TICKS(2000));

    // 设置呼吸效果
    effect = LED_EFFECT_BREATH;
    ws2812_set(strip, color, effect);

    // 等待一段时间
    vTaskDelay(pdMS_TO_TICKS(5000));

    // 关闭所有 LED
    effect = LED_EFFECT_OFF;
    ws2812_set(strip, color, effect);
}
```

## 依赖项

- ESP-IDF >= 4.4.7
- led_strip 灯条驱动库

## 许可证

本项目采用 MIT 许可证。更多信息请参阅 [LICENSE](LICENSE) 文件。

## 贡献

欢迎任何形式的贡献，包括但不限于代码改进、文档更新、问题反馈等。请通过 GitHub 提交 Pull Request 或 Issue。

## 作者

- 宁子希

## 版本历史

- 0.1 (2024-08-31)
  - 初始版本发布

## 联系方式

如有任何问题或建议，请通过 GitHub Issues 或电子邮件联系。