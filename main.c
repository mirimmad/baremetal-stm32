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

  clk_enable_port(PORTA_CLOCK);
  clk_enable_port(PORTC_CLOCK);

  set_pin_mode(GPIOA, P5, OP);
  set_pin_mode(GPIOC, P13, IN);
  while(1) {
    uint8_t b = read_pin(GPIOC, P13);
   // uint32_t idr = GPIOC->IDR & (1 << 13);
    //uint8_t _break = 100;
    if (b) 
      write_pin(GPIOA, P5, LOW);
    else 
      write_pin(GPIOA, P5, HIGH);
  }
  /*
  set_pin_mode(GPIOA, P5, OP);
  toggle:
  write_pin(GPIOA, P5, HIGH);
  delay();
  write_pin(GPIOA, P5, LOW);
  delay();
  goto toggle;
  */

  while(1){};

}