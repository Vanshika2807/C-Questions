
//  bitXor - x ^ y using only ~ and &
//  Example bitXor(4, 5) = 1
//  Legal ops:  ~ &  
//  Max ops: 14

//   bitAnd - x & y using only ~ and |
//  Example bitAnd(6, 5) = 4
//  Legal ops:  ~ |  
// Max ops: 8

/*
* getByte - extract byte n from word x
* Examples: getByte(0x12345678, 1)  = 0x56
*Legal ops: ! ~ & ^| + << >>
Max ops: 6
*/

/*
* sign - return 1 if positive, 0 if zero, and -1 if negative
* Examples: sign(130) = 1, sign(-23) = -1
* Legal ops: ! ~ & ^ | + << >>
* Max ops : 10
*/

/* logicalShift - shift x to the right by n, using a logical shift
*  can assume that 0 <=n<=31
* examples: logicalShift(0x87654321, 4) = 0x8765432
*  Legal ops:  ~ & ^ | + << >>
*Max ops: 20
*/

/*
* conditional - same as x ? y : z
* example conditional (2, 4, 5) = 4
* ! ~ & ^ | + << >>
* Max ops: 16
*/

/* bang - Compute !x without using !
*  Examples: bang(3)=0, bang(0)=1
*  Legal ops: ~ & ^ | + << >>
*  Max ops: 12
*/ 

#include<stdio.h>

int bitXor (int x, int y) {
    int a = x & ~y;
    int b = ~x & y;

     return ~(~a & ~b);
}


int bitAnd (int x, int y) {

     return  ~( ~x | ~y);
}

int sign(int x){
    int a = (x>>31) & 1;
    return  a | (!x << 1);
}

int getByte(int x, int n) {
    return (x>>(n<<3)) & 255;
    //&255 bcoz to maintain the identity or preseve bits
    //<<3 bcoz then it would be 2^3 = 8 bits 
}

int logicalShift(int x, int n) {
    int mask = ~(((1<<31)>>n) << 1);
    return (x>>n) & mask;
}


int conditional(int x, int y, int z) {
    int mask = !!x;
    int val = (mask << 31) >> 31;
    return (y & val) | (z & ~val);
}


int bang(int x) {
    int signBits = (x >> 31) | ((~x + 1) >> 31);
    // XOR the result with 1 to get the final answer
    return (signBits ^ 1) & 1;}

int main(){
    int ans = logicalShift(10,2);
    printf("%d ", ans);
}


