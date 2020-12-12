//#include "swap.h"


void swap(int** x, int** y)
{
    //int volatile temp;
    int* temp = *x;
    *x = *y;
    *y = temp;

}   

int main()
{
   
    int x  = 10;
    int y  = 50;
    
       
    int* px = &x;
    int* py = &y;   
    
    swap(&px, &py);
    
    printf("%d", *px);
    printf("%d", *py);
    
    return 0;
}

