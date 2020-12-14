
// LD1 --> PA5 -- Homework
// LD2 --> PB14 -- In Class
#include <stdint.h>

#include "stm32l475xx.h"

#define RCC_BASE 0x40021000
#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))


#define GPIOA_BASE 0x48000000
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x00)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))

#define ORD5    (1<<5)


volatile int counter=0;

void delay(void);
void delay(void)
  
{
    counter = 0;
    while(counter < 100000)
    {
        counter ++;
    }
        GPIOA->ODR ^= GPIO_ODR_OD5;
}

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
    // Set bit[29:28] to 0x01  so --> 0x400 // To enable PB14 as output
    GPIOB->MODER &= ~GPIO_MODER_MODE5_1;
    GPIOB->MODER |= GPIO_MODER_MODE5_0;
    
    // GPIO port output data register (GPIOx_ODR) (x = A..E and H)
    // GPIOB Base Address: 0x48000400
    // Address offset: 0x14
    // Set bit[14] to 1 --> 0x4000; // Turn LED ON
    // Set bit[14] to 0 --> 0x0; // Turn LED OFF
    
    while(1)
    {
        delay();
    }    

}