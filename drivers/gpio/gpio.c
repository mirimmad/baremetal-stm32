#include "gpio.h"


void set_gpioa() {
    GPIOA = (GPIO_TYPE *)GPIOA_BASE;
}

void set_pin_mode(GPIO_TYPE *gpio, pin_t pin , mode_t mode) {
    gpio->MODER |= mode << (pin * 2);
}

void write_pin(GPIO_TYPE *gpio, pin_t pin, state_t state) {
    if (state == HIGH) {
        gpio->BSRR |= 1 << pin;
    } else {
        gpio->BSRR |= 1 << (pin + 16);
    }
}
