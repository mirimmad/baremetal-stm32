#include <stdint.h>
#include <stm32f401xe.h>

static void delay(void) {
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 100; j++) {
            __asm volatile("nop");
        }
    }
}


int main(void) {
    
  RCC->AHB1ENR |= 1 << 0;
  GPIOA->MODER |= 1 << 10;

  while (1) {
    GPIOA->BSRR |= 1 << 5;
    delay();

    GPIOA->BSRR |= 1 << 21;
    delay();

  }

}