/* CSC 406 Section 801 Winter 2018
 Homework assignment 3 part 1
 Write the 4 functions below as specified
 in the homework write-up.  The the hw3.c
 that you submit, there should be no main
 funtion.  YOu should also remove the
 #include <string.h> below.  Although my main
 code uses functions from the string library,
 you are not allowed to use any <string.h> library
 functions in any of the code you write.
 This part is worth 4 points.
 */

#include <stdio.h>
#include <string.h>

int strcmp406(char str1[], char str2[]) {
    int i = 0;
    int len1 =0 ,len2 = 0, c;
    for(c = 0; str1[c]!='\0';c++){
        len1 ++;
    }
    for(c = 0; str2[c]!='\0';c++){
        len2 ++;
    }
    if (len1 >= len2){
        int x,y;
        while (str1[i]!= '\0'){
            x = str1[i];
            y = str2[i];
            if (x==y){
                i++;
            }
            else{
                break;
            }
        }
        return x-y;
    }
    else {
        int x,y;
        while (str2[i]!= '\0'){
            x = str1[i];
            y = str2[i];
            if (x==y){
                i++;
            }
            else{
                break;
            }
        }
        return x-y;
    }
}

char *strcat406(char *str1, char *str2) {
    int a,b,len1=0,len2=0;
    int i = 0 , j = 0,x;
    for (a = 0; str1[a]!='\0'; a++){
        len1++;
    }
    for (b = 0; str2[b]!='\0'; b++){
        len2++;
    }
    int c = len1+len2;
    while (i <= c){
        x = str1[i];
        if (x == '\0'){
            str1[i] = str2[j];
            j++;
            i++;
        }
        else {
            i++;
            
        }
        
    }
    return str1;
    
}

char *strchr406(char str[], char c){
    while (*str != '\0'){
        if (*str == c){
            return str;
        }
        str++;
    }
    if (*str == c){
        return str;
    }
    return 0;
}



char *strncpy406(char dest[], char src[], int len) {
    while (*dest != '\0'){
        
        *dest = *src;
        *de
    }
    for (i = 0; i<len && dest!='\0';i++);
    *dest[i] = *sec[i];
}
int main() {
    char str1[100];
    char str2[100];
    char small[4];
    strcpy(str1, "bin");
    strcpy(str2, "bag");
    
    printf("Problem 1\n\n");
    
    printf("strcmp406(\"%s, %s\") = %d\n", str1, str2, strcmp406(str1, str2));
    strcpy(str1, "computer");
    strcpy(str2, "game");
    printf("strcmp406(\"%s\", \"%s\") = %d\n", str1, str2, strcmp406(str1, str2));
    strcpy(str1, "computer");
    strcpy(str2, "computer");
    printf("strcmp406(\"%s\", \"%s\") = %d\n",
           str1, str2, strcmp406(str1, str2));
    strcpy(str1, "are");
    strcpy(str2, "area");
    printf("strcmp406(\"%s\", \"%s\") = %d\n", str1, str2,
           strcmp406(str1, str2));
    
    printf("\nProblem 2\n\n");
    
    strcpy(str1,"comp");
    strcpy(str2,"uter");
    char str3[10] = "comp";
    char *p = strcat406(str3, str2);
    printf("After strcat406, str1 is %s\n", str1);
    printf("After strcat406, str2 is %s\n", str2);
    printf("strcat406(str3,str2) should return %s", p);
    
    printf("\nProblem 3\n\n");
    
    char ababc[] = "abcbc";
    char *s = ababc;
    char *sb = strchr406(s, 'b');
    printf("Address of 'b' in %s is %x\n", ababc, sb);
    printf("String is %s\n", sb);
    char *sc = strchr406(s,'c');
    printf("Address of 'c' in %s is %x\n", ababc, sc);
    printf("String is %s\n", sc);
    char *sd = strchr406(s,'d');
    printf("Address of 'd' in %s is = %d\n", ababc, sd);
    
    printf("\nProblem 4\n\n");
    printf("Not sure about the correct answers for these");
    printf("I'll run them using <string.h> and let you know by Friday.");
    
    char four_1[] = "comp";
    char four_2[] = "systems";
    strncpy(four_1,four_2,4);
    printf("four_1 should be syst and it is %s\n", four_1);
    strcpy(four_1, "computer");
    strncpy(four_1,four_2+2,4);
    printf("four_1 should be csys and it is %s\n", four_1);
}





























