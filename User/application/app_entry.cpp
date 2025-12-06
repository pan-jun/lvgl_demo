#include "app_entry.h"
#include "stm32f1xx_hal.h"
#include "usart.h"
#include <cstdint>
#include <cstdio>
#include <cstring>

void app_entry(void)
{
    uint32_t counter = 0;
    char msg[32];
    std::memset(msg, 0, 32);

    while (true) {
        std::sprintf(msg, "Hello, STM32! %d\r\n", counter++);
        HAL_UART_Transmit(&huart1, reinterpret_cast<uint8_t *>(msg), sizeof(msg),
                          HAL_MAX_DELAY);
        HAL_Delay(1000);
    }
}
