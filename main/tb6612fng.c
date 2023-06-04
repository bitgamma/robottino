#include "tb6612fng.h"
#include <driver/mcpwm.h>
#include <driver/gpio.h>
#include <math.h>

void tb6612fng_init() {
	gpio_config_t conf;

	conf.intr_type = GPIO_INTR_DISABLE;
	conf.mode = GPIO_MODE_OUTPUT;
	conf.pin_bit_mask = BIT64(TB6612FNG_STDBY) | BIT64(TB6612FNG_CH1_IN1) | BIT64(TB6612FNG_CH1_IN2) | BIT64(TB6612FNG_CH1_PWM) | BIT64(TB6612FNG_CH2_IN1) | BIT64(TB6612FNG_CH2_IN2) | BIT64(TB6612FNG_CH2_PWM);
	conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
	conf.pull_up_en = GPIO_PULLUP_DISABLE;
    
    gpio_config(&conf);
    tb6612fng_stdby(true);

	mcpwm_config_t pwm_conf;

	pwm_conf.frequency = 1000;
	pwm_conf.cmpr_a = 0;
	pwm_conf.cmpr_b = 0;
	pwm_conf.counter_mode = MCPWM_UP_COUNTER;
	pwm_conf.duty_mode = MCPWM_DUTY_MODE_0;

	mcpwm_init(0, 0, &pwm_conf);
    mcpwm_gpio_init(0, TB6612FNG_CH1, TB6612FNG_CH1_PWM);
    mcpwm_gpio_init(0, TB6612FNG_CH2, TB6612FNG_CH2_PWM);

    tb6612fng_set_speed(TB6612FNG_CH1, 0.);
    tb6612fng_set_speed(TB6612FNG_CH2, 0.);
}

void tb6612fng_stdby(bool stdby) {
    gpio_set_level(TB6612FNG_STDBY, !stdby);
}

void tb6612fng_set_speed(tb6612fng_ch_t ch, float speed) {
    gpio_num_t in1, in2;

    if (ch == TB6612FNG_CH1) {
        in1 = TB6612FNG_CH1_IN1;
        in2 = TB6612FNG_CH1_IN2;
    } else {
        in1 = TB6612FNG_CH2_IN1;
        in2 = TB6612FNG_CH2_IN2;
    }

    if (speed == 0) {
        gpio_set_level(in1, 1);
        gpio_set_level(in2, 1);
    } else if (speed > 0) {
        gpio_set_level(in1, 1);
        gpio_set_level(in2, 0);
    } else if (speed < 0) {
        gpio_set_level(in1, 0);
        gpio_set_level(in2, 1);
    }

    mcpwm_set_duty(0, 0, ch, fabs(speed));
}
