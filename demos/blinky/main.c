
#include <gpio/gpio.h>
#include <clk/clk.h>

void delay() {
    for (int i = 0 ; i < 10000; i++) {
        for (int j  = 0 ; j < 100; j++) {
            __asm volatile("nop");        
        }
    }
}

int main() {
    config_clk84();
    clk_enable_port(PORTA_CLOCK);
    
    set_pin_mode(GPIOA, P5, OP);
    toggle:
    write_pin(GPIOA, P5, HIGH);
    delay();
    write_pin(GPIOA, P5, LOW);
    delay();
    goto toggle;
    while(1);

}
