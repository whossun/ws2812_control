/**
 * @file ws2812_control.h
 * @author 宁子希
 * @brief    WS2812灯条控制
 * @version 0.1
 * @date 2024-08-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef WS2812_CONTROL_H
#define WS2812_CONTROL_H

#include <stdint.h>
#include "led_strip.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#ifdef __cplusplus
extern "C" {
#endif

// led_color_t 结构体表示 LED 灯的颜色
typedef struct {
    uint32_t red;
    uint32_t green;
    uint32_t blue;
} led_color_t;

// 定义颜色宏
#define COLOR_WHITE  (led_color_t){255, 255, 255}  // 白色
#define COLOR_GREEN  (led_color_t){0, 255, 0}      // 绿色
#define COLOR_RED    (led_color_t){255, 0, 0}      // 红色
#define COLOR_BLUE   (led_color_t){0, 0, 255}      // 蓝色
#define COLOR_YELLOW (led_color_t){255, 255, 0}    // 黄色
#define COLOR_CYAN   (led_color_t){0, 255, 255}    // 青色
#define COLOR_MAGENTA (led_color_t){255, 0, 255}   // 洋红色
#define COLOR_BLACK  (led_color_t){0, 0, 0}        // 黑色
#define COLOR_ORANGE (led_color_t){255, 165, 0}    // 橙色
#define COLOR_PURPLE (led_color_t){128, 0, 128}    // 紫色
#define COLOR_PINK   (led_color_t){255, 192, 203}  // 粉色
#define COLOR_GRAY   (led_color_t){128, 128, 128}  // 灰色
#define COLOR_BROWN  (led_color_t){165, 42, 42}    // 棕色
#define COLOR_LIME   (led_color_t){0, 255, 0}      // 酸橙绿
#define COLOR_TEAL   (led_color_t){0, 128, 128}    // 蓝绿色
#define COLOR_NAVY   (led_color_t){0, 0, 128}      // 海军蓝
#define COLOR_FUCHSIA (led_color_t){255, 0, 255}   // 紫红色
#define COLOR_MAROON (led_color_t){128, 0, 0}      // 栗色
#define COLOR_OLIVE  (led_color_t){128, 128, 0}    // 橄榄绿

// led_effect_t 枚举类型表示 LED 灯的效果类型
typedef enum {
    // 关闭LED灯效果
    LED_EFFECT_OFF,
    // 使LED灯常亮效果
    LED_EFFECT_ON,
    // 使LED灯呼吸效果
    LED_EFFECT_BREATH,
    // 使LED灯淡入效果
    LED_EFFECT_FADE_IN,
    // 使LED灯慢闪烁效果
    LED_EFFECT_BLINK_SLOW,
    // 使LED灯快闪烁效果
    LED_EFFECT_BLINK_FAST,
    // 使LED灯彩虹效果
    LED_EFFECT_RAINBOW
} led_effect_t;

/**
 * @brief  创建WS2812控制句柄
 * 
 * @return led_strip_t* - WS2812控制句柄
 */
led_strip_t* ws2812_create();

/**
 * @brief 设置单个LED的颜色
 * 
 * @param strip - WS2812控制句柄
 * @param index - LED的索引
 * @param color - LED的颜色
 */
void set_led_color(led_strip_t *strip, int index, led_color_t color);

/**
 * @brief 使所有LED常亮
 * 
 * @param strip - WS2812控制句柄
 * @param color - LED的颜色
 */
void led_set_on(led_strip_t *strip, led_color_t color);

/**
 * @brief 关闭所有LED
 * 
 * @param strip - WS2812控制句柄
 */
void led_set_off(led_strip_t *strip);

/**
 * @brief 使所有LED呼吸效果
 * 
 * @param strip - WS2812控制句柄
 * @param color - LED的颜色
 */
void led_set_breath(led_strip_t *strip, led_color_t color);

/**
 * @brief 使所有LED缓缓亮起
 * 
 * @param strip - WS2812控制句柄
 * @param color - LED的颜色
 */
void led_set_fade_in(led_strip_t *strip, led_color_t color);

/**
 * @brief 使所有LED微微闪烁
 * 
 * @param strip - WS2812控制句柄
 * @param color - LED的颜色
 * @param count - 闪烁次数
 */
void led_set_blink_slow(led_strip_t *strip, led_color_t color, int count);

/**
 * @brief 使所有LED快速闪烁
 * 
 * @param strip - WS2812控制句柄
 * @param color - LED的颜色
 * @param count - 闪烁次数
 */
void led_set_blink_fast(led_strip_t *strip, led_color_t color, int count);

/**
 * @brief 使所有LED彩虹效果
 * 
 * @param strip - WS2812控制句柄
 */
void led_set_rainbow(led_strip_t *strip);

/**
 * @brief 自选LED效果
 * 
 * @param strip - WS2812控制句柄
 * @param color - LED的颜色
 * @param effect - LED的效果类型
 */
void ws2812_set(led_strip_t *strip, led_color_t color, led_effect_t effect);

/**
 * @brief 更新LED显示
 * 
 * @param strip - WS2812控制句柄
 */
void update_led_display(led_strip_t *strip);

#ifdef __cplusplus
}
#endif

#endif // WS2812_CONTROL_H