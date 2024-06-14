#include "gpio.h"


void set_pin_mode(GPIO_TYPE *gpio, pin_t pin, pin_mode_t mode)
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

void set_pin_speed(GPIO_TYPE *gpio, pin_t pin, pin_speed_t speed) {
    gpio->OSPEEDR |= speed << ( pin * 2);
}

void set_pin_push_pull(GPIO_TYPE *gpio, pin_t pin, pin_push_pull_t pp) {
    gpio->PUPDR |= pp << (pin * 2);
}