/* CS261- Assignment 1 - Q. 0*/
/* Name: Kim McLeod
 * Date: 7.1.15
 * Solution description: Print addresses and values of variable and pointer.
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){

     /*Print the value pointed to by iptr*/
    printf("Value pointed to by iptr: %d\n", *iptr);

     /*Print the address pointed to by iptr*/
    printf("Address pointed to by iptr: %p\n", iptr);

     /*Print the address of iptr itself*/
    printf("Address of iptr: %p\n", &iptr);
}

int main(){
    
    /*Declare an integer x*/
    int x = 20;

    /*print the address of x*/
    printf("\n Address of x: %p\n", &x);

    /*call fooA with the address of x as the argument*/
    fooA(&x);

    /*print the value of x*/
    printf("Value of x: %d\n", x);
    
    return 0;
} 
