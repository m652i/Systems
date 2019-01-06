#include <stdio.h>
#include <string.h>

// Problem 1:  place your answer below

/*
 3 bytes
 24 bits
 Largest positive number => 0111 1111 1111 1111 1111 1111
 First pointer becomes 1 so goes negative => 1000 0000 0000 0000 0000 0000
 Smallest possible number represented by data type "medium"
 
 Ans : 0xff800000 (-8388608)
 */

// Problem 2:  strswap
void strswap(char *str1, char *str2) {
    char strtmp[30];
    strcpy(strtmp, str1);
    strcpy(str1, str2);
    strcpy(str2, strtmp);
}

// Problem 3:  log_base_2
// assume that x is at least 1
int log_base_2(unsigned int x) {

    int y;
    2^y = x;
        
    return y;  // replace this
    
}

// Problem 4:  fill in the printf statements below
// in order to achieve the desired output
void p4() {
    char letters[] = "abc";
    
    // THE NEXT LINE SHOULD PRINT abc
    printf("%s\n", letters);
    
    // THE NEXT LINE SHOULD PRINT c
    printf("%c\n", *letters+2
           );
    
    // THE NEXT LINE SHOULD PRINT bc
    printf("%c%c\n",  *letters+1, *letters+2);
    
}

// Problem 5:  squares
int squares(int *x, int len) {
    int i = 1;
    while (i<=len){
        if (*x+i/ *x == 2){
            i++;
            return 1;
        }
        else{
            break;
            return 0;
        }
    }
}// Problem 6:

/*
 Decimal -  Binary  -  Hex
 17   - 00010001 - 0x11      16+1 = 2^4+2^0     hex 0001 => 1 0001 => 1 hence 11
 -6   - 11111010 - 0xfa      11111010 => 00000101+1 = 00000110 => 4+2 = 6  (negative 6) hex 1111 = f 1010 = a
 43   - 00101011 - 0x2b      2 =>0010 b=> 1011   2^5+2^3+2+2^0 = 32+8+2+1
 
 
 // Problem 7:
 Decimal  -  Binary Sci Notation  -  IEEE 32 bit floating point
 0.625   -     1.01 * 2^-1       -    0x3f200000
 -5     -    -1.01 * 2^2        -    0xc0a00000
 
 */
// A main function to test your code. Please
// leave this main in the mid.c file that you
// upload to D2L.
int main() {
    char str1[10] = "computer";
    char str2[10] = "systems";
    char str3[10] = "I";
    strswap(str1, str3);
    strswap(str2, str3);
    printf("This should print I computer systems\n");
    printf("%s %s %s\n", str1, str2, str3);
    int i;
    printf("log_base_2 output should be 0 2 3 4 4\n");
    for (i=1; i<16; i+=3)
        printf("%d ", log_base_2(i));
    printf("\n");
    p4();
    int sq1[] = {2, 4, 16};
    int sq2[] = {3, 9, 81, 100};
    int sq3[] = {5, 25};
    printf("The following should print x 0 y, where x and y must be non-zero\n");
    printf("%d %d %d\n", squares(sq1,3), squares(sq2,4),
           squares(sq3,2));
}

