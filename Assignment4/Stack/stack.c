#include "stack.h"

#define STACK_SIZE 3

// Backing store
int StackStore[STACK_SIZE];

// Pointers to stack elements for adding and retrieving
int* putPtr;
int* getPtr;
int i;

void stack_init(void)
{
    putPtr = 0;
    getPtr = 0;
    for(int i =0; i<STACK_SIZE; i++)
    {
        StackStore[i] = 0;
    }
}

int stack_push(int data)
{
    if (stack_full())
        // stack is full
    {
        return -1;
    }
    
    *putPtr = data;

    i++ ;
    
    if (stack_full()!= 1)
    {
        putPtr++;
        //stack is empty
    }
        return 0;  

}

int stack_pop(int* data)
{   
    if (stack_empty)
    {
        // stack is empty
        return -1;
    }

    *data = *getPtr;   
    
    i-- ;
    
   if( i != (STACK_SIZE-1))
    {
        putPtr;
    }
    
    return 0;
}


