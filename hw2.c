/* CSC 406 Section 801 Winter 2018
   Homework assigment 2
   Due: date and time specified on the D2L dropbox
    
   
   Name : Po Han Chen
   ID : 1889504
   Section : CSC406
 
 
*/

#include <iostream>
#include <stdio.h>
using namespace std;

void add_to_array(int a [], int x , int y) {
    int i = 0;
    int len = sizeof(a);
    if(x >= len){
        x = len;
    }
    for (i; i < x; i++){
        a[i] = a[i] + y;
        printf("%d ",a[i]);
    }
    printf("\n");
}

void add(int x, int y){
    int z = x + y;
    printf("%d\n",z);
}
void call_add(){
    int x,y;
    cout<< "Please enter first integer : ";
    cin >> x;
    cout << "Please enter second integer : ";
    cin >> y;
    add(x,y);
}

void copy_array(int a[], int b[], int x) {
    int i = 0;
    for(i; i < x; i++){
        b[i] = a[i];
    }
}
void reverse_array(int a [], int x) {
    int i = 0;
    int len = sizeof(a);
    int front, back;
    if(x >= len){
        x = len;
    }
    for(i; i < x/2 ; i++) {
        front = a[i];
        back = a[len - 1 - i];
        a[i] = back;
        a[len - 1 - i] = front;
    }
}







void convert_temp(int t1, char s1, int *t2, char *s2) {
    if (s1 == 'c' or s1 == 'C'){
        *t2 = (t1 * 9/5) +32;
        *s2 = 'F';
    }
    if (s1 == 'f' or s1 == 'F'){
        
        *t2 = (t1 - 32) * 5/9;
        *s2 = 'C';
    }
    printf("%d %c\n", *t2, *s2);
}
void call_cvt_temp(){
    char s1,s2;
    int t1,t2;
    cout<< "Please enter F or C : ";
    cin >> s1;
    cout << "Please enter tempurature (int only) : ";
    cin >> t1;
    convert_temp(t1,s1,&t2,&s2);
}
