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

#define GPIOA ((GPIO_TYPE *)GPIOA_BASE)
#define GPIOB ((GPIO_TYPE *)GPIOB_BASE)
#define GPIOC ((GPIO_TYPE *)GPIOC_BASE)

typedef enum
{
    P0 = 0,
    P1,
    P2,
    P3,
    P4,
    P5,
    P6,
    P7,
    P8,
    P9,
    P10,
    P11,
    P12,
    P13,
    P14,
    P15,
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
} pin_mode_t;

typedef enum
{
    LOW_SPEED = 0b00,
    MEDIUM_SPEED = 0b01,
    HIGH_SPEED = 0b10,
    VERY_HIGH_SPEED = 0b11,
} pin_speed_t;

typedef enum
{
    NO_PP = 0b00,
    PU = 0b01,
    PD = 0b10,
    res = 0b11,
} pin_push_pull_t;

void set_pin_mode(GPIO_TYPE *gpio, pin_t pin, pin_mode_t mode);
void set_pin_speed(GPIO_TYPE *gpio, pin_t pin, pin_speed_t speed);
void set_pin_push_pull(GPIO_TYPE *gpio, pin_t pin, pin_push_pull_t pp);
void write_pin(GPIO_TYPE *gpio, pin_t pin, state_t state);
uint8_t read_pin(GPIO_TYPE *gpio, pin_t pin);

#endif