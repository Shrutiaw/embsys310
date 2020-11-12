
#if 1

#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x48000000

#define RCC_AHB2ENR (*((unsigned int*)(RCC_BASE + 0x4C)))
#define GPIOA_MODER (*((unsigned int*)(GPIOA_BASE + 0x0)))
#define GPIOA_ODR (*((unsigned int*)(GPIOA_BASE + 0x14)))
#define ORD5 (1<<5)
#define DOT_TIME ((unsigned int)100000)
#define DASH_TIME ((unsigned int)(DOT_TIME*3))
#define WORD_SPACE ((unsigned int)(DASH_TIME*5))

const char lc_ptr[]="... .... .-. ..- - ..";
const unsigned int ed_morse_size = (sizeof(lc_ptr)/sizeof(char));

int counter =0;

void ledToggle(unsigned int timer)
{
      counter =0; 
      GPIOA_ODR^= ORD5;
      while(counter < timer)
   {
        counter ++;
    }    
} 
 void c_Unit(const char* elem)
 {
     switch(*elem)
     {
     case '.':
     ledToggle(DOT_TIME); 
     break;
     default:
         
      ledToggle(DASH_TIME); 
     break;   
 }
 }   
  int main()
  {
    RCC_AHB2ENR |= 0x1;
    GPIOA_MODER &= 0xFFFFF7FF;  
  while(1)
  {
    for (int a=0; a <ed_morse_size - 1; a++)
    {
    c_Unit(&lc_ptr[a]);
    
    if(lc_ptr[a+1]!=' '&& lc_ptr[a]!=' ')
     {
         ledToggle(DOT_TIME);
      }
    }
   counter =0;
   while (counter < WORD_SPACE) 
     {
         counter ++;
     }    
   }  
  }
#endif