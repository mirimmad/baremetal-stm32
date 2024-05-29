#ifndef __NVIC_DRIVER_
#define __NVIC_DRIVER_

#include "mmap.h"

#define NVIC_PRIORITY_BITS 4

typedef struct
{
    volatile uint32_t ISER[8];  // Interrupt Set Enable Registers
    volatile uint32_t res1[24]; // reserved
    volatile uint32_t ICER[8];  // Interrupt Clear Enable Registers
    volatile uint32_t res2[24];
    volatile uint32_t ISPR[8]; // Interrupt Set Pending Resgisters
    volatile uint32_t res3[24];
    volatile uint32_t ICPR[8]; // Interrupt Clear Pending Registers
    volatile uint32_t res4[24];
    volatile uint32_t IABR[8]; // Interrupt Active Bit Registers
    volatile uint32_t res5[56];
    volatile uint32_t IPR[240]; // Interrupt Priority Registers
    volatile uint32_t res6[644];
    volatile uint32_t STIR; // Software Trigger Interrupt Register

} NVIC_TYPE;

#define NVIC ((NVIC_TYPE *)NVIC_BASE)

typedef struct
{
    uint32_t IMR;   // Interrupt Mask Register
    uint32_t EMR;   // Event Mask Register
    uint32_t RTSR;  // Rising Trigger Selection Register
    uint32_t FTSR;  // Faling Trigger Selection Register
    uint32_t SWIER; // Software Interrupt Event Register
    uint32_t PR;    // Pending Register
} EXTI_TYPE;

#define EXTI ((EXTI_TYPE *)EXTI_BASE)

typedef enum
{
    // STM32 specific Interrupt numbers

    WWDG_IRQ = 0,                // Window WatchDog Interrupt
    PVD_IRQ = 1,                 // PVD through EXTI Line detection Interrupt
    TAMP_STAMP_IRQ = 2,          // Tamper and TimeStamp interrupts through the EXTI line
    RTC_WKUP_IRQ = 3,            // RTC Wakeup interrupt through the EXTI line
    FLASH_IRQ = 4,               // FLASH global Interrupt
    RCC_IRQ = 5,                 // RCC global Interrupt
    EXTI0_IRQ = 6,               // EXTI Line0 Interrupt
    EXTI1_IRQ = 7,               // EXTI Line1 Interrupt
    EXTI2_IRQ = 8,               // EXTI Line2 Interrupt
    EXTI3_IRQ = 9,               // EXTI Line3 Interrupt
    EXTI4_IRQ = 10,              // EXTI Line4 Interrupt
    DMA1_Stream0_IRQ = 11,       // DMA1 Stream 0 global Interrupt
    DMA1_Stream1_IRQ = 12,       // DMA1 Stream 1 global Interrupt
    DMA1_Stream2_IRQ = 13,       // DMA1 Stream 2 global Interrupt
    DMA1_Stream3_IRQ = 14,       // DMA1 Stream 3 global Interrupt
    DMA1_Stream4_IRQ = 15,       // DMA1 Stream 4 global Interrupt
    DMA1_Stream5_IRQ = 16,       // DMA1 Stream 5 global Interrupt
    DMA1_Stream6_IRQ = 17,       // DMA1 Stream 6 global Interrupt
    ADC_IRQ = 18,                // ADC1, ADC2 and ADC3 global Interrupts
    EXTI9_5_IRQ = 23,            // External Line[9:5] Interrupts
    TIM1_BRK_TIM9_IRQ = 24,      // TIM1 Break interrupt and TIM9 global interrupt
    TIM1_UP_TIM10_IRQ = 25,      // TIM1 Update Interrupt and TIM10 global interrupt
    TIM1_TRG_COM_TIM11_IRQ = 26, // TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt
    TIM1_CC_IRQ = 27,            // TIM1 Capture Compare Interrupt
    TIM2_IRQ = 28,               // TIM2 global Interrupt
    TIM3_IRQ = 29,               // TIM3 global Interrupt
    TIM4_IRQ = 30,               // TIM4 global Interrupt
    I2C1_EV_IRQ = 31,            // I2C1 Event Interrupt
    I2C1_ER_IRQ = 32,            // I2C1 Error Interrupt
    I2C2_EV_IRQ = 33,            // I2C2 Event Interrupt
    I2C2_ER_IRQ = 34,            // I2C2 Error Interrupt
    SPI1_IRQ = 35,               // SPI1 global Interrupt
    SPI2_IRQ = 36,               // SPI2 global Interrupt
    USART1_IRQ = 37,             // USART1 global Interrupt
    USART2_IRQ = 38,             // USART2 global Interrupt
    EXTI15_10_IRQ = 40,          // External Line[15:10] Interrupts
    RTC_Alarm_IRQ = 41,          // RTC Alarm (A and B) through EXTI Line Interrupt
    OTG_FS_WKUP_IRQ = 42,        // USB OTG FS Wakeup through EXTI line interrupt
    DMA1_Stream7_IRQ = 47,       // DMA1 Stream7 Interrupt
    SDIO_IRQ = 49,               // SDIO global Interrupt
    TIM5_IRQ = 50,               // TIM5 global Interrupt
    SPI3_IRQ = 51,               // SPI3 global Interrupt
    DMA2_Stream0_IRQ = 56,       // DMA2 Stream 0 global Interrupt
    DMA2_Stream1_IRQ = 57,       // DMA2 Stream 1 global Interrupt
    DMA2_Stream2_IRQ = 58,       // DMA2 Stream 2 global Interrupt
    DMA2_Stream3_IRQ = 59,       // DMA2 Stream 3 global Interrupt
    DMA2_Stream4_IRQ = 60,       // DMA2 Stream 4 global Interrupt
    OTG_FS_IRQ = 67,             // USB OTG FS global Interrupt
    DMA2_Stream5_IRQ = 68,       // DMA2 Stream 5 global interrupt
    DMA2_Stream6_IRQ = 69,       // DMA2 Stream 6 global interrupt
    DMA2_Stream7_IRQ = 70,       // DMA2 Stream 7 global interrupt
    USART6_IRQ = 71,             // USART6 global interrupt
    I2C3_EV_IRQ = 72,            // I2C3 event interrupt
    I2C3_ER_IRQ = 73,            // I2C3 error interrupt
    FPU_IRQ = 81,                // FPU global interrupt
    SPI4_IRQ = 84,

} IRQ_Type;

void enable_irqs();
void disable_irqs();

void nvic_enable_irq(IRQ_Type irqn);
void nvic_disable_irq(IRQ_Type irqn);
void nvic_set_priority(IRQ_Type irqn, uint8_t priority);

#endif