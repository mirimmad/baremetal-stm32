#ifndef _CLK_DRIVER_
#define _CLK_DRIVER_

#include "mmap.h"

typedef struct
{
    // control register
    uint32_t CR;
    // PLL config register
    uint32_t PLLCFGR;
    // config register
    uint32_t CFGR;
    // interrupt register
    uint32_t CIR;
    // AHB1 peripheral reset register
    uint32_t AHB1RSTR;
    // AHB2 peripheral reset register
    uint32_t AHB2RSTR;
    uint32_t res1[2];
    // APB1 peripheral reset register
    uint32_t APB1RSTR;
    // APB2 peripheral reset register
    uint32_t APB2RSTR;
    uint32_t res2[2];
    // AHB1 peripheral clock enable register
    uint32_t AHB1ENR;
    // AHB2 peripheral clock enable register
    uint32_t AHB2ENR;
    uint32_t res3[2];
    // APB1 peripheral clock enable register
    uint32_t APB1ENR;
    // APB2 peripheral clock enable register
    uint32_t APB2ENR;
    uint32_t res4[2];
    // AHB1 peripheral clock enable in low power register
    uint32_t AHB1LPENR;
    // AHB2 peripheral clock enable in low power register
    uint32_t AHB2LPENR;
    uint32_t res5[2];
    // APB1 peripheral clock enable in low power register
    uint32_t APB1LPENR;
    // APB2 peripheral clock enable in low power register
    uint32_t APB2LPENR;
    uint32_t res6[2];
    // backup domain control register
    uint32_t BDCR;
    // clock control and status register
    uint32_t CSR;
    uint32_t res7[2];
    // spread spectrum clock generation register
    uint32_t SSCGR;
    // PLLI2S config register
    uint32_t PLLI2S;
    // dedicated clocks config register
    uint32_t DCKCFGR;

}
__attribute__((packed)) RCC_TYPE;

#define RCC ((RCC_TYPE *)RCC_BASE)

typedef enum
{
    PORTA_CLOCK = 0b0,
    PORTB_CLOCk,
    PORTC_CLOCK,
} PORT_CLOCK;

void clk_enable_port(PORT_CLOCK port);
void clk_disable_port(PORT_CLOCK port);

#endif