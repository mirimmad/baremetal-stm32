#include "clk.h"

// configure PLL for 84Mhz (max) output
void config_PLL()
{

    // disable the PLL
    RCC->CR &= ~(1 << 24);
    // wait for it to be zero
    while ((RCC->CR & (1 << 25)) == 1);
    // PLL config
    // Vo = Vin * (N * M) / P
    // Vin = 8 Mhz (HSE)
    // N = 336, M = 8, P = 4
    // Load the config
    // set HSE as PLL source
    RCC->PLLCFGR |= (1 << 22);
    // set value of M divisor
    RCC->PLLCFGR |= (8 << 0);
    // set value of N multiplier
    RCC->PLLCFGR |= (336 << 6);
    // set value P divisor
    RCC->PLLCFGR |= (0b01 << 16);
    // set value of Q
    RCC->PLLCFGR |= (4 << 24);

    // turn PLL on
    RCC->CR |= (1 << 24);
    // wait for it
    while ((RCC->CR & (1 << 25)) == 0);
}

// sets the system clock to 84MHz (max)
// This also leads to APB2 run at 84Mhz and
// APB1 run at 42 MHz (both max) since no pre-scalars
// are used
void config_clk84()
{
    SystemClock = 16000000;

    // using PLL with HSE as source

    // turn HSE on
    RCC->CR |= (1 << 16);
    // wait fot it
    while ((RCC->CR & (1 << 17)) == 0);

    config_PLL();
    // use PLL as SystemClock
    RCC->CFGR |= (0b10 << 0);
    while (((RCC->CFGR >> 2) & 0x00000003) != 0b10);
    // 2 wait states in the FLASH ACR reg
    *(uint32_t *)0x40023C00 |= 0b010;
    SystemClock = 84000000;
}

void clk_enable_port(PORT_CLOCK port)
{
    RCC->AHB1ENR |= (1 << port);
}

void clk_disable_port(PORT_CLOCK port)
{
    RCC->AHB1ENR &= ~(1 << port);
}