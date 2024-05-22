#ifndef _MMAP_
#define _MMAP_

#include <stdint.h>

#define SCS_BASE 0xE000E000U
#define SysTick_BASE (SCS_BASE + 0x0010)
#define NVIC_BASE (SCS_BASE + 0x0100)
#define SCB_BASE (SCS_BASE + 0x0D00)

#define RCC_BASE 0x40023800

#define GPIOA_BASE 0x40020000
#define GPIOB_BASE 0x40020400
#define GPIOC_BASE 0x40020800

#endif