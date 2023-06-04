#include <freertos/FreeRTOS.h>
#include <freertos/task.h>

#include "uni_esp32.h"
#include "uni_platform_robottino.h"
#include "tb6612fng.h"

static void control_main_loop(void* arg) {
    tb6612fng_stdby(false);

    while(1) {
        tb6612fng_set_speed(TB6612FNG_CH1, robottino_get_left());
        tb6612fng_set_speed(TB6612FNG_CH2, robottino_get_right());
        vTaskDelay(pdMS_TO_TICKS(50));
    }
}

int app_main(void) {
    tb6612fng_init();
    xTaskCreatePinnedToCore(control_main_loop, "control_main_loop", 8192, NULL, 1, NULL, 1);
    return uni_esp32_main();
}
