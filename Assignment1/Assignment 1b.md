


The advantage of using Two's complement is that it automatically generates sign bit.

When performing arithmatic operations on binary numbers it is easier to use two's complement for both negative and positive numbers. 

In 2s-complement representation, we represent a positive number as it is and negative number by its corresponding 2s-complement. In this way, arithmatic operation doesn't need to have any special logic(circuit) for dealing with negative numbers.

For example,

1) When adding 5 + 2: 
-- addition of binary (5) + binary (2)

00101
+
00010
——------
00111

2) When subtracting 5 - 2, rewriting as 5 + (-2):
-- addition of binary (5) + 2's complement of binary (2)

00101
+
11110 (2s-complement of 2)
——-
00011


With two's complement, the bit at the far left of the bit pattern i.e the most significant bit is used to indicate positive or negative and the remaining 
bits are used to store the actual size of the number.

Positive numbers always start with a 0. Four-bit, positive, two's complement numbers would be 0000 = 0, 0001 = 1, up to 0111 = 7. The smallest positive number is the smallest binary value.

Negative numbers always start with a 1. The smallest negative number is the largest binary value. 1111 is -1, 1110 is -2, 1101 is -3, etc down to 1000 which represents -8.

