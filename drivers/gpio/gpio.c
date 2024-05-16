#include "gpio.h"

void set_gpioa()
{
    GPIOA = (GPIO_TYPE *)GPIOA_BASE;
}

void set_pin_mode(pin_t pin, mode_t mode)
{
    if (pin >= PA0 && pin <= PA15)
        GPIOA->MODER |= mode << (pin * 2);
}

void write_pin(pin_t pin, state_t state)
{
    if (pin >= PA0 && pin <= PA15)
    {
        if (state == HIGH)
        {
            GPIOA->BSRR |= 1 << pin;
        }
        else
        {
            GPIOA->BSRR |= 1 << (pin + 16);
        }
    }
}
