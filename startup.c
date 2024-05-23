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
void SysTickHandler(void);

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
    *(uint32_t*)0xE000ED0C |= (1 << 2);
}

void SysTickHandler(void) {
    __asm__("bkpt 1");
}