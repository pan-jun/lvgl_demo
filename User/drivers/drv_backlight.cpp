#include "drv_backlight.hpp"
#include <cstdint>

void DRV_backlight::set_backlightness(uint16_t value)
{
    if (!set_backlightness_cb) {
        return;
    }

    value = value < backlightness_min ? backlightness_min : value;
    value = value > backlightness_max ? backlightness_max : value;
    set_backlightness_cb(value);
}

void DRV_backlight::set_backlightness(float percent)
{
    if (!set_backlightness_cb) {
        return;
    }

    percent = percent < 0.0f ? 0.0f : percent;
    percent = percent > 1.0f ? 1.0f : percent;

    uint16_t value = percent * (backlightness_max - backlightness_min) + backlightness_min;
    set_backlightness_cb(value);
}
