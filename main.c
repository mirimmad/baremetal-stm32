#include <stdint.h>

#define RCC_BASE 0x40023800UL
#define GPIOA_BASE 0x40020000UL

#define RCC_AHB1ENR RCC_BASE + 0x30
#define GPIOA_MODER GPIOA_BASE + 0x00
#define GPIOA_BSSR GPIOA_BASE + 0x18

#define DEREF(p) *(uint32_t *) (p)

static void delay(void) {
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 100; j++) {
            __asm volatile("nop");
        }
    }
}


int main(void) {
    /*
    int val2 = 1;
    int val = 0;
    while(1) {
        val += 1;
    }
    */

   DEREF(RCC_AHB1ENR) |= 1 << 0;
   DEREF(GPIOA_MODER) |= 1 << 10;

   while(1) {
    DEREF(GPIOA_BSSR) |= 1 << 5;
    delay();

    DEREF(GPIOA_BSSR) |= 1 << 21;
    delay();
   }

}