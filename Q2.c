/* CS261- Assignment 1 - Q.2*/
/* Name: Kim McLeod
 * Date: 7.1.15
 * Solution description: prints three values, modifies them, and prints again
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){

    /*Set a to double its original value*/
    *a = *a * 2;

    /*Set b to half its original value*/
    *b = *b / 2;

    /*Assign a+b to c*/
    c = *a + *b; 

    /*Return c*/
    return c;
}

int main(){

    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x, y, z;
    x = 5;
    y = 6;
    z = 7;

    /*Print the values of x, y and z*/
    printf("x: %d\n y: %d\n z: %d\n", x, y, z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
    /*Print the value returned by foo*/
    printf("Foo result: %d\n", foo(&x, &y, z));
    
    
    /*Print the values of x, y and z again*/
    printf("x: %d\n y: %d\n z: %d\n", x, y, z);


    /*Is the return value different than the value of z?  Why?*/
    
    /* The return value is different because we passed z by value, so foo only received a copy
     * of z, but not the actual variable z. The copy of z was changed, but the original z wasn't.*/


    return 0;
}
    
    
