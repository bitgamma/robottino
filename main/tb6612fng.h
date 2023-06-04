#ifndef _TB6612FNG_H_
#define _TB6612FNG_H_

#include <stdbool.h>
#include <driver/gpio.h>

#define TB6612FNG_CH1_IN1 GPIO_NUM_25
#define TB6612FNG_CH1_IN2 GPIO_NUM_33
#define TB6612FNG_CH1_PWM GPIO_NUM_32

#define TB6612FNG_STDBY GPIO_NUM_26

#define TB6612FNG_CH2_IN1 GPIO_NUM_27
#define TB6612FNG_CH2_IN2 GPIO_NUM_14
#define TB6612FNG_CH2_PWM GPIO_NUM_12

typedef enum {
    TB6612FNG_CH1 = 0,
    TB6612FNG_CH2
} tb6612fng_ch_t;

void tb6612fng_init();
void tb6612fng_stdby(bool stdby);
void tb6612fng_set_speed(tb6612fng_ch_t ch, float speed);

#endif
