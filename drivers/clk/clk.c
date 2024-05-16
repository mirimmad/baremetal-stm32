#include "clk.h"

void set_clk()
{
    RCC = (RCC_TYPE *)RCC_BASE;
}

void clk_enable_porta()
{
    RCC->AHB1ENR |= (1 << 0);
}

void clk_disable_porta()
{
    RCC->AHB1ENR &= (0 << 0);
}