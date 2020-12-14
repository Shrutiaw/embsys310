#include "stdint.h"
#include "delay.h"
//#include "stm32f401xe.h"    // CMSIS - Device Specific File
#include "system_stm32l4xx.h"
#include "stm32l475xx.h"

// LD1 --> PA5 -- Homework
// LD2 --> PB14 -- In Class


#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))


#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))


#define ORD5    (1<<5)
//int delay_val;

void SysTick_Initialize(void);
void delay (uint32_t delay_val) ;
static uint32_t elapsed ;

//void unit32_t delay_val = 1u ;     // 1ms

//void unit32_t delay_val = 50000u; // 5s
//void unit32_t delay_val = 100000u; //10s

int main()

{     
    // RCC AHB2 peripheral clock enable register (RCC_AHB2ENR)
    // RCC Base Address: 0x40021000
    // Address offset: 0x4C
    // Set bit[1] to 1
    // 1. Enable clock to Peripheral  
    RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
    
    // GPIO port mode register (GPIOx_MODER) (x = A..E and H)
    // GPIOB Base Address: 0x48000400
    // Address offset: 0x00
    // Set bit[29:28] to 0x01  so --> 0x400 // To enable PA5 as output
    GPIOA->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOA->MODER |= GPIO_MODER_MODE5_0;
    
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // GPIOB Base Address: 0x48000400
    // Address offset: 0x14
    // Set bit[5] to 1 --> 0x4000; // Turn LED ON
    // Set bit[5] to 0 --> 0x0; // Turn LED OFF
    
    while(1)
    {

        GPIOA->ODR ^= GPIO_ODR_OD5;
        delay(200);
    }    
}
    
#define SYS_CLOCK_HZ_MS 40000u;
int delay_val ;
int delay_ms ;
void delay(uint32_t dealy_ms)
{
    int elapse_ms = delay_ms * SYS_CLOCK_HZ_MS ; 
    
    SysTick->LOAD = elapse_ms- 1;       // 0xE000E014 - Counts down to 0.
    SysTick->VAL = 0x0;                     // 0xE000E018 - Clears initial value
    SysTick->CTRL = 0x7;                // 0xE000E010 - Enable interrupts 
      while (SysTick->VAL)
    {
       }
} 

   
void SysTick_Handler(void)
{
    __disable_irq();
    int temp_delay = delay_val;
    
    while(temp_delay)
    {
        temp_delay --;
    }
    __enable_irq();
}
