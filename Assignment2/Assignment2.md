
1)After injecting 0x7FFFFFFF for the counter value in the variable window and then step thru the program once, following changes were observed:\
a)The value of the counter from the Locals window is -2147483648.\
b)The value of the counter in the Registers window i.e R1 is 0x80000000.\
c)The N flag is set to 1 as the result of the operation was negative following the two's complement operation /,and the V flag was set t 1 as the operation produced a signed overflow.

  For example: 0x7FFFFFFF is largest positive two's complement integer that can be represented in 32 bits so 0x7FFFFFFF + 0x7FFFFFFF triggers a signed overflow, but not an unsigned overflow. The result is 0xFFFFFFE and it is correct if interpreted as an unsigned quantity, but represents a negative value i.e -2 if interpreted as a signed. 


2)After injecting 0xFFFFFFFF for the counter value in the variable window and then step thru the program once, following changes were observed:\
a)The value of counter in the Locals is 0.\
b)The N flag is set to 0 as the result was zero in locals. As the value is set to 0 there will be no sign overflow , so the V flag is set to 0.\

3)By changing the counter variable type in the code to unsigned int and injecting the values 0x7FFFFFFF then step thru the program once , the values are:\
a)The value of counter in the Locals window is 2147483648. After incrementing each value in the the values are 2147483649 and so on. The 2147483648 is a negative value which is two's complement of 0x7FFFFFFF.\
b)The N and V flags are set in the APSR register.After one step thru the value becomes negative as the limit for unsigned int is 0- 4,294,967,295 which is equivalent to the limit for signed int(-2,147,483,648 to 2,147,483,647).

4)By changing the counter variable type in the code to unsigned int and injecting the values 0xFFFFFFFF then step thru the program once , the values are:\
a)The value of counter in the Locals window is 1. After incrementing each value in the counter the values are 2, 3 and so on.\
b)The N and V flags are not set as the value in the counter is positive value.

5)The counter variable is moved outside of main.\
a)the scope of the variable counter is global.\
b)It is not visible in the locals window.\
c)The counter variable can be tracked in the watch window.\
d)The address of the counter variable in memory is 0x20000000.

6)\
a)The value of counter at the end of the program (halting at the return 0 statement) is 4.\
b)The counter value has changed from 0 to 4 as counter is global variable and initialized to 0 . The p_int is pointing to 0 and increment in p_int would result in increment in counter.\

7)\
a)The address where counter is stored is 0x20000000.\
b)The program counter variable is stored in RAM.\
c)The value of counter at the end of the program (halting at the return 0) is 4.