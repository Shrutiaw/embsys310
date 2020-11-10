#if 1

#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x48000000

#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))
#define ORD5 (1<<5)

volatile int counter =0;
int main()
{
    RCC_AHB2ENR |= 0x1;
    GPIOA_MODER &= 0xFFFFF7FF;
    int counter = 0;
  
  while(1)
  {
      counter =0;
     while(counter < 100000) 
     {
         counter ++;
     }
     GPIOA_ODR^= ORD5;
       counter =0;
   while(counter < 100000) 
     {
         counter ++;
     }
          GPIOA_ODR^= ORD5;
}
}
#endif

