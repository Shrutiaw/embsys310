#include<stdio.h>
#include<assert.h>
#include"stack.h"

int main()
{
    // *******************************************************************
    // Test1: Retrieve item from an empty stack
    // *******************************************************************
    int var1;
    int var2;
    int var3;
    
  
    int result=1;
    int test_var=5;
    
    
    // Arrange:
    stack_init();
    
    // Act:
    result= stack_pop(&var1);
      
    // Assert:
    assert(-1 == result);
    assert(1 == var1);
    assert(0== stack_empty());
    
    // *******************************************************************
    // Test2: Successfully retrieve an item from the stack
    // *******************************************************************
    // Arrange:
    var1=1; var2=2; var3=3;
    
    
    // Act
   stack_push(var1); 
   stack_push(var2); 
   stack_push(var3); 
   
    // Assert:
    assert(-1 ==stack_push(5));
    
    assert(1 == stack_full());
    
    assert(0 == stack_pop(&test_var));
    assert(6== test_var);  
        
    assert(0 == stack_pop(&test_var));
    assert(7== test_var);      
 
    assert(0 == stack_pop(&test_var));
    assert(8== test_var);


    
    // *******************************************************************
    // Test3: Fill stack, then get all items.
    // *******************************************************************
    // Arrange:
   
    stack_init();
    var1 =10; var2=20; var3=30;
    
    // Act:
    stack_push(var1);
    stack_push(var2);
    stack_push(var3);                                    
    
    // Assert:
    assert(0 == stack_pop(&test_var));
    assert(30 == test_var);

    assert(0 == stack_pop(&test_var));
    assert(20 == test_var);
    
    assert(0== stack_push(50));
    assert(0== stack_push(60));
    
    assert(-1== stack_push(70));
      
    assert(0== stack_empty());
                           
    assert(1== stack_full());
     
 return 0;
 }                