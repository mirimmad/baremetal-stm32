#include <stdint.h>

extern uint32_t _sidata;
extern uint32_t  _sdata;
extern uint32_t _edata;
extern uint32_t _sbss;
extern uint32_t _ebss;

extern void _estack(void);

extern int main(void);

void reset_handler(void);

__attribute__((used, section(".vector_table"))) void (*const vectors[])(void) = {
    &_estack,
    reset_handler,
};

//__attribute__((used, section(".reset_handler")))
void reset_handler(void) {
    
    uint32_t * pSrc = &_sdata;
    uint32_t * pDest = &_sidata;
    uint32_t * pEnd = &_edata;

    for (; pSrc != pEnd;) {
        *pDest++ = *pSrc++;
    }

    for (pDest = &_sbss; pDest < &_ebss;) {
        *pDest++ = 0;
    }
    

    main();

    while(1);
}