#ifndef _GPIO_DRIVER_
#define _GPIO_DRIVER_

#include "mmap.h"

typedef struct
{
    // four configuration registers
    uint32_t MODER;
    uint32_t TYPER;
    uint32_t OSPEEDR;
    uint32_t PUPDR;
    // two data registers
    uint32_t IDR;
    uint32_t ODR;
    // bit set/reset register
    uint32_t BSRR;
    // locking register
    uint32_t LCKR;
    // alternate function register
    uint32_t AFRH;
    uint32_t ARRL;
} __attribute__((packed)) GPIO_TYPE;

GPIO_TYPE *GPIOA;

typedef enum
{
    PA0 = 0,
    PA1,
    PA2,
    PA3,
    PA4,
    PA5,
    PA6,
    PA7,
    PA8,
    PA9,
    PA10,
    PA11,
    PA12,
    PA13,
    PA14,
    PA15,
} pin_t;

typedef enum
{
    LOW = 0b0,
    HIGH = 0b1
} state_t;

typedef enum
{
    IN = 0b00,
    OP = 0b01,
    AF = 0b10,
    AN = 0b11
} mode_t;


void set_gpioa();
void set_pin_mode(GPIO_TYPE *gpio, pin_t pin, mode_t mode);
void write_pin(GPIO_TYPE *gpio, pin_t pin, state_t state);

#endif