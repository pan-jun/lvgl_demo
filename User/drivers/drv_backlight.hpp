#ifndef __DRV_BACKLIGHT_HPP__
#define __DRV_BACKLIGHT_HPP__

#include <cstdint>

class DRV_backlight {
    public:
        using set_backlightness_t = void (*)(uint16_t value);
        
        DRV_backlight(set_backlightness_t cb, uint16_t min = 0, uint16_t max = 1000) : 
            backlightness_min(min), backlightness_max(max), set_backlightness_cb(cb) {
                cb(min);
            }
        ~DRV_backlight(void) {}

        void set_backlightness(uint16_t value);
        void set_backlightness(float percent);

    private:
        uint16_t backlightness_min = 0;
        uint16_t backlightness_max = 1000;
        set_backlightness_t set_backlightness_cb = nullptr;
};

#endif // __DRV_BACKLIGHT_HPP__
