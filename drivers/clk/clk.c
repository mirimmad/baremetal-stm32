#include "clk.h"

void clk_enable_port(PORT_CLOCK port)
{
    RCC->AHB1ENR |= (1 << port);
}

void clk_disable_port(PORT_CLOCK port)
{
    RCC->AHB1ENR &= ~(1 << port);
}