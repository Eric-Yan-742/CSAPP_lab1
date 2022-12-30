/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
  /* Eliminate bit of both 1 */
  int noBothOne = ~(x & y);
  /* Eliminate bit of both 0 */
  int noBothZero = ~(~x & ~y);
  /* Eliminate bit of both 0 and both 1 */
  return noBothOne & noBothZero;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  int tmin = 1;
  return tmin << 31;

}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  x = ~x;
  /* The negate of the complement of Tmax (1000...000) equal to itself */
  /* But the negate of 0 is also itself. Use (!!x) to exclude case of 0 */
  return !(x ^ (~x + 1)) & !!x;
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
#define equal(x, y) (!((x) ^ (y)))
int allOddBits(int x) {
  /* Create a mask of 0xAAAAAAAA */
  unsigned mask = 0xAA + (0xAA << 8);
  mask = mask + (mask << 16);
  /* Number with all odd-numbered bits equal to 1 & mask will be equal to mask */
  return equal(x & mask, mask);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
  return !((x >> 4) ^ 0x3) & !!(((x & 0xf) + (~0xA + 1)) & (1 << 31));
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  /* Convert x to boolean value */
  int toBool = !!x;
  /* Get the negate of toBool */
  int negate = ~toBool + 1;
  /* Bit pattern of (-1): 111...111 */
  /* Bit pattern of (-0): 000...000 */
  return (negate & y) | (~negate & z);
}
/*
 * Helper Method less
 * Return 1 if x < y, otherwise return 0
*/
inline static int less(int x, int y)
{
  #define flagx ((x & (1 << 31)))  
  #define flagy ((y & (1 << 31)))
  #define notE (flagx ^ flagy) 
  #define toBool(x) (!!(x))
  #define less_positive(x, y) (toBool((((x) + negate(y)) & (1 << 31))))
  return conditional(notE, (flagx >> 31) & 1, less_positive(x, y));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  return (!(x ^ y)) | less(x, y);
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  return ((x | (~x + 1)) >> 31) + 1;
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /* Ultimate goal: get x's highest bit of 1 */

  /* Get the complement of x if x is less than 0 */
  /* To unify the way we get the number of bits of positive number and negative number*/
  x = conditional((x >> 31), ~x, x);

  int bit_16 = 0, bit_8 = 0, bit_4 = 0, bit_2 = 0, bit_1 = 0, bit_0 = 0;
  /* Similar to binary search */
  
  /* Check whether higher 16 bits of x have 1 */
  /* if higher 16 bits have 1, discard lower 16 bits*/
  /* (Check 1 in the higher 16 bits later)*/
  /* If higher 16 bits don't have 1, discard higher 16 bits*/
  /* (Check 1 in the lower 16 bits later) */
  bit_16 = toBool(x >> 16) << 4;
  x >>= bit_16;
  
  /* Vice versa for the following */
  bit_8 = toBool(x >> 8) << 3;
  x >>= bit_8;

  bit_4 = toBool(x >> 4) << 2;
  x >>= bit_4;

  bit_2 = toBool(x >> 2) << 1;
  x >>= bit_2;

  bit_1 = toBool(x >> 1) << 0;
  x >>= bit_1;

  bit_0 = toBool(x);

  return bit_16 + bit_8 + bit_4 + bit_2 + bit_1 + bit_0 + 1; 
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  /* Cut the float pattern into 3 parts */  
  unsigned s = uf >> 31;
  unsigned exp = (uf << 1) >> 24;
  unsigned frac = (uf << 9) >> 9;
  /* uf == NaN */
  if(equal(exp, 0xFF)) {
    return uf;
  }
  /* exp == 0 && frac == 0 */
  if(equal(exp, 0) && equal(frac, 0)) {
    return uf;
  }
  /* exp == 0 && frac != 0 (Denormalized) */
  if(equal(exp, 0)) {
    return (s << 31) + (frac << 1);
  }
  /* exp != 0 (Normalized) */
  return (s << 31) + ((exp + 1) << 23) + frac;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
  unsigned s = uf >> 31;
  unsigned e = (uf << 1) >> 24;
  unsigned frac = (uf << 9) >> 9;
  if(equal(e, 0xFF)) {
    return (1 << 31);
  }
  if(equal(e, 0)) {
    return 0;
  }

  /* Normalized */
  int exponent = e - 127;
  frac = frac | (1 << 23); //add implicit leading 1
  if(exponent > 30) { //if overflow
    return (1 << 31);
  } 
  if(exponent < 0) {
    return 0;
  }

  if(exponent >= 23) {
    frac <<= exponent - 23; //if exponent >= 23, expand frac
  } else {
    frac >>= 23 - exponent; //if exponent < 23, cut frac
  }

  if(s) {
    return ~frac + 1;
  }
  return frac;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
  /* The only method I figure out completely by myself :) */
  int exponent = x;
  /* If too small, return 0 */
  if(exponent < -149) {
    return 0;
  }
  /* If too large, return +INF */
  if(exponent > 127) {
    return (0xFF << 23);
  }
  unsigned s = (x >> 31) & 1;
  unsigned frac = 0;
  unsigned e = 0;
  /* Denormalized */
  if(exponent >= -149 && exponent <= -127) {
    e = 0;
    frac = 1 << (149 + x);
  }
  /* Normalized */
  if(exponent >= -126) {
    frac = 0;
    e = exponent + 127;
  }
  return (s << 31) + (e << 23) + frac;
}
