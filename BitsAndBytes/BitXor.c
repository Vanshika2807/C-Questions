
//  bitXor - x ^ y using only ~ and &
//  Example bitXor(4, 5) = 1
//  Legal ops:  ~ &  
//  Max ops: 14

//   bitAnd - x & y using only ~ and |
//  Example bitAnd(6, 5) = 4
//  Legal ops:  ~ |  
// Max ops: 8


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
    
}

int main(){
    int ans = bitXor(10,12);
    printf("%d ", ans);
}


