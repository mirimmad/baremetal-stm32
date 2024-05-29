#include "nvic.h"

void enable_irqs()
{
    __asm__("cpsie i");
}

void disable_irqs()
{
    __asm__("cpsid i");
}

void nvic_enable_irq(IRQ_Type irqn)
{
    if (irqn >= 0 && irqn <= 31)
    {
        NVIC->ISER[0] |= 1 << irqn;
    }
    else if (irqn >= 32 && irqn <= 63)
    {
        NVIC->ISER[1] |= 1 << (irqn - 32);
    }
    else if (irqn >= 64 && irqn <= 95)
    {
        NVIC->ISER[2] |= 1 << (irqn - 64);
    }
}

void nvic_disable_irq(IRQ_Type irqn)
{
    if (irqn >= 0 && irqn <= 31)
    {
        NVIC->ICER[0] |= 1 << irqn;
    }
    else if (irqn >= 32 && irqn <= 63)
    {
        NVIC->ICER[1] |= 1 << (irqn - 32);
    }
    else if (irqn >= 64 && irqn <= 95)
    {
        NVIC->ICER[2] |= 1 << (irqn - 64);
    }
}

void nvic_set_priority(IRQ_Type irqn, uint8_t priority)
{
    if (irqn >= 0)
        NVIC->IPR[irqn] = (uint8_t)((priority << NVIC_PRIORITY_BITS) & 0xFF);
}