#include <stdint.h>

extern uint32_t _etext;
extern uint32_t  _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;


extern void _estack(void);

extern int main(void);

void reset_handler(void);

void defaultHandler(void);
void SysTickHandler(void) __attribute__((weak));
void EXTI9_5_Handler(void) __attribute__((weak));
void EXT15_10_Handler(void) __attribute__((weak));

__attribute__((used, section(".vector_table"))) void (*const vectors[])(void) = {
    &_estack,
    reset_handler, // reset handler
    defaultHandler, // NMI
    defaultHandler, // Hard Fault
    defaultHandler, // MemManage
    defaultHandler, // Bus Fault
    defaultHandler, // Usage Fault
    defaultHandler, // reserved
    defaultHandler, // reserved
    defaultHandler, // reserved
    defaultHandler, // reserved
    defaultHandler, // SVCall
    defaultHandler, // debug monitor
    defaultHandler, // reserved
    defaultHandler, // PendSV
    SysTickHandler, // System tick timer (SysTick)

    defaultHandler, // Window WatchDog
    defaultHandler, // PVD through EXTI Line detection
    defaultHandler, // Tamper and TimeStamps through the EXTI line
    defaultHandler, // RTC Wakeup through the EXTI line
    defaultHandler, // FLASH
    defaultHandler, // RCC

    defaultHandler, // EXTI Line0
    defaultHandler, // EXTI Line1
    defaultHandler, // EXTI Line2
    defaultHandler, // EXTI Line3
    defaultHandler, // EXTI Line4

    defaultHandler, // DMA1 Stream 0
    defaultHandler, // DMA1 Stream 1
    defaultHandler, // DMA1 Stream 2
    defaultHandler, // DMA1 Stream 3
    defaultHandler, // DMA1 Stream 4
    defaultHandler, // DMA1 Stream 5
    defaultHandler, // DMA1 Stream 6
    defaultHandler, // ADC1, ADC2 and ADC3s

    defaultHandler, // reserved
    defaultHandler, // reserved
    defaultHandler, // reserved
    defaultHandler, // reserved

    EXTI9_5_Handler, // EXT1 Lines[9:5]
    defaultHandler,
    defaultHandler,
    defaultHandler,
    defaultHandler,
    defaultHandler,
    defaultHandler,
    defaultHandler,
    defaultHandler,
    defaultHandler,
    defaultHandler,
    defaultHandler,
    defaultHandler,
    defaultHandler,
    defaultHandler,
    defaultHandler,
    defaultHandler,
    EXT15_10_Handler, // EXT1 Lines[15:10]

};

__attribute__((used, section(".reset_handler")))
void reset_handler(void) {
    
    uint32_t * pSrc = &_etext;
    uint32_t * pDest = &_sdata;

    if  (pSrc != pDest) {
        for (; pDest < &_edata;) {
            *pDest++ = *pSrc++;
        }
    }

    for (pDest = &_sbss; pDest < &_ebss;) {
        *pDest++ = 0;
    }
    
    main();

    while(1);
}

void defaultHandler(void) {
    // AIRCR
    // cause system reset
    //*(uint32_t*)0xE000ED0C |= (1 << 2);
    __asm__("bkpt 2");
}

void SysTickHandler(void) {
    __asm__("bkpt 1");
}

void EXTI9_5_Handler(void) {
    __asm__("bkpt 3");
}

void EXT15_10_Handler(void) {
    __asm__("bkpt 4");
}