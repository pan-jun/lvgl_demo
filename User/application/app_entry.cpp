#include "app_entry.h"
#include "stm32f1xx_hal.h"
#include "usart.h"
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include "lvgl.h"
#include "ui_demo.h"
#include "app_test_all.hpp"

#if 0
    void my_flush_cb(lv_display_t *display, const lv_area_t *area, uint8_t *px_map)
    {
        // lv_draw_sw_rgb565_swap(px_map, (area->x2 - area->x1) * (area->y2 - area->y1) * 2);
        /*The most simple case (but also the slowest) to put all pixels to the screen one-by-one
        *`put_px` is just an example, it needs to be implemented by you.*/
        // uint16_t * buf16 = (uint16_t *)px_map; /*Let's say it's a 16 bit (RGB565) display*/
        // int32_t x, y;
        // for(y = area->y1; y <= area->y2; y++) {
        //     for(x = area->x1; x <=  area->x2; x++) {
        //         bsp_nv3030b_draw_point(x, y, *buf16);
        //         buf16++;
        //     }
        // }

        /* IMPORTANT!!!
        * Inform LVGL that you are ready with the flushing and buf is not used anymore*/
        lv_display_flush_ready(display);
    }

    void drive_init(void)
    {
        lv_display_t *display = lv_display_create(240, 284);
        lv_display_set_flush_cb(display, my_flush_cb);
        lv_display_set_buffers(display, buf, NULL, sizeof(buf), LV_DISPLAY_RENDER_MODE_PARTIAL);
        lv_tick_set_cb(xTaskGetTickCount);
    }

    void app_entry(void)
    {
        lv_init();
        drive_init();
        ui_demo_init(NULL);

        while (true) {
            lv_timer_handler();
            HAL_Delay(5);
        }
    }
#else 
    void app_entry(void)
    {
        app_test_all();

        while (true) {
            std::printf("std++: hello world\r\n");
            HAL_Delay(1000);
        }
    }
#endif

