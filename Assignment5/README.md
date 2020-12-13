1)Create a function in “C” that allows swapping of two pointers.
a) Explain what the “main” function does in order to setup the input arguments prior to calling the swap_pointer() function?

-The main function passes the address of the pointers.


b) What are the values in R0 & R1 when swap_pointer() is called?


-Before swap

![Before](/Assignment5/Images/Before.jpg)

-After Swap

![After](/Assignment5/Images/After.jpg)

-The values of R0 and R1 after the swap_pointer is called are 


![R0,R1](/Assignment5/Images/R0,R1.jpg)


c) Share a screen shot of the local variables inside of “main” after the function swap_pointer() returns showing the values of the pointers and what they are pointing to

-

![c](/Assignment5/Images/c.jpg)





2)Create a new file divAsm.s and add the file to the same HelloWorld project above.


a) Start with the Assembly demo code shared in class (available under Module_06).
b) Write the assembly code to take an input argument, divide it by 2, and return the result.
c) Invoke the function “PrintString” from within divAsm before doing the division computation.
d) Add a comment for every statement in your assembly function code.
e) Invoke divAsm() inside of your main function in main.c
f) Run your program on the board and capture a snapshot image of the output from TeraTerm showing the result of the divAsm.

-


![divAsm](/Assignment5/Images/divAsm.jpg)





3)Implement a swap function in assembly and call it “swapCharsAsm”:
a. It takes as input two variables of char data type each and swaps the two chars.

-
b. Add a comment for every statement in your assembly function code.






