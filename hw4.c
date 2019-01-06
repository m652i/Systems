#include <stdio.h>

/*
 CSC 406 Section 801 Winter 2018
 Homework assignment 4
 Due:  Date and time as specified on D2L
 
 In this assignment, you must complete
 the 5 functons below.  Each function's body
 must consist of just a single C statement.
 Furthermore, the statement must not be a control
 statement, such as if, switch, or any kind of loop.
 For each problem, you are also restricted to the
 operators and constants as specified.
 */

/* 1.  Write a function which zeros a variable x.  A
 pointer to x is passed as a parameter.  YOU MAY
 USE NO CONSTANTS in this function, and must
 restrict yourself to using the assignment operator,
 the dereferencing operator, and one or more of
 the bitwise operators.
 */

void zero(int *xptr) {
    *xptr = *xptr >> 33;
}

/* 2.  Write a function to set x to be the maximum unsigned long
 integer.  The parameter passed to the function is a
 pointer to x.  You may only use the constant 0 in
 this function, and must restrict yourself to using
 the assignment operator, the dereferencing operator,
 and the bitwise operators.
 */

void maximum(unsigned long *xptr) {
    *xptr = 0;
    *xptr = ~*xptr>>1;
}

/* 3.  Write a function to set x to be the minimum long
 integer.  The parameter passed to the function is a
 pointer to x.  You may only use the constants 0-63 in
 this function, and must restrict yourself to using
 the assignment operator, the dereferencing operator,
 the bitwise operators, and the shift operators.
 */


void minimum(long *xptr) {
    unsigned long a = *xptr = 0;
    a = ~(~a>>1);
    *xptr = a;
}

/* 4.  Write a function which sets the integer x to negative x.
 The parameter passed to the function is a pointer to x.
 You may only use the constant 1 in this function,
 and must restrict yourself to the assignment operator,
 the dereferencing operator, the bitwise operators, and
 the + operator.
 */

void negative(int *xptr) {
    *xptr = ~*xptr+1;
}

/* 5.  Write a function called set_byte.  It is passed 3
 parameters:  a pointer to an unsigned integer x, an
 index i, and a new value v for the byte.
 The function should change the ith byte of x to
 v.  Byte 0 is x's least significant byte; byte 1
 is the next least significant byte, etc.; byte 3
 is x's most significant byte.  You may only use the
 constants 0-4 in this function, and must restrict
 yourself to the the assignment operator, the
 dereferencing operator, multiplication, bitwise
 operators and shift operators.
 */

void set_byte(unsigned int *xptr, int i, char v) {
    *xptr = (*xptr >> (8*i));
    *xptr = (*xptr << (8*i))+v;
}

int main() {
    int x;
    int *xptr = &x;
    long l;
    long *lptr = &l;
    unsigned long ul;
    unsigned long *ulptr = &ul;
    unsigned int y;
    unsigned int *yptr = &y;
    
    zero(xptr);
    printf("zero %d\n", x);
    maximum(ulptr);
    printf("max %#lx %ld\n", ul, ul);
    minimum(lptr);
    printf("min %#lx %ld\n", l, l);
    x = 3;
    negative(xptr);
    printf("negative %d\n", x);
    x = 15;
    y = 15;
    
    set_byte(yptr, 1, 15);
    printf("%#x\n", y);
    
}
