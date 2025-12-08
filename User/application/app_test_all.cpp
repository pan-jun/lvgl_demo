#include "app_test_all.hpp"
#include "drv_backlight.hpp"
#include "tim.h"
#include <stdint.h>

// ...existing code...
void set_backlightness_cb(uint16_t value)
{
    (void)__HAL_TIM_SET_COMPARE(&htim4, TIM_CHANNEL_1, value);
}

void app_test_all(void)
{
    DRV_backlight backlight1(set_backlightness_cb, 0, 1000);
    for (int16_t i = 1000; i >= 0; i -= 50) {
        backlight1.set_backlightness(static_cast<uint16_t>(i));
        HAL_Delay(100);
    }

    for (uint16_t i = 0; i <= 1000; i += 50) {
        backlight1.set_backlightness(i);
        HAL_Delay(100);
    }
}
