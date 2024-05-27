#include "gpio.h"


void set_pin_mode(GPIO_TYPE *gpio, pin_t pin, mode_t mode)
{
    gpio->MODER |= mode << (pin * 2);
}

void write_pin(GPIO_TYPE *gpio, pin_t pin, state_t state)
{
    if (state == HIGH)
        gpio->ODR |= 1 << pin;
    else
        gpio->ODR &= ~(1 << pin);
}

uint8_t read_pin(GPIO_TYPE *gpio, pin_t pin)
{
    return ((gpio->IDR & (1 << pin)) == 0) ? HIGH : LOW;
}