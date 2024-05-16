#include <stdint.h>
//#include <stm32f401xe.h>
#include <clk.h>
#include <gpio.h>

static void delay(void) {
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < 100; j++) {
            __asm volatile("nop");
        }
    }
}


int main(void) {
    /*
  RCC->AHB1ENR |= 1 << 0;
  GPIOA->MODER |= 1 << 10;

  while (1) {
    //GPIOA->BSRR |= 1 << 5;
    GPIOA->ODR |= (1 << 5);
    delay();

    //GPIOA->BSRR |= 1 << 21;
    GPIOA->ODR &= ~(1 << 5);
    delay();

  }
  */

  set_clk();
  clk_enable_porta();

  set_gpioa();
  set_pin_mode(GPIOA, PA5, OP);
  toggle:
  write_pin(GPIOA, PA5, HIGH);
  delay();
  write_pin(GPIOA, PA5, LOW);
  delay();
  goto toggle;

  while(1){};

}