1.
a)What instructions does the compiler produce in assembly for writing to the GPIO bit when using bit-band address?

- The instructions produced by the compiler are :
   MOVS     R0, #1
   LDR.N    R1, [PC, #0x3c]         ; 0x4242'0980
   STR      R0,[R1]

b)What were the instructions produced when writing to the GPIOx_ODR without using bit-banding?

-The instructions produced by the compiler are :
  LDR.N     R0, [PC, #0x40]         ; 0x4002'104C
  LDR       R1, [R0]
  ORRS.W    R1, R1, #1
  STR       R1, [R0]



2.
a)How does the calling function func2 pass the values to the calledfunction func1?

-The main function of func2 is to call func1 and initialize the required values. The compiler then generates BL instruction to jump to func2 , which will be loaded in PC to perform as next instruction.

b)What extra code did the compiler generate before calling the function func1 with the multiple arguments?

-Before calling the function func1 with the multiple arguments, following extra code was generated :
  
  BL        func2
  MOVS      R0, #0
  

c)What extra code did the compiler generate inside the called function funct1 with the multiple list of arguments?

-The compiler generate following extra code inside the called function funct1 with the multiple list of arguments :

  PUSH      {R4}
  LDR       R4, [SP, #0x4]

d)Any other observations?

- POP commands are seen func1 and func2.
-After func1 :
  POP       {R4}
-After func2 :
  POP        {R0, PC}