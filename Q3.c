/* CS261- Assignment 1 - Q.3*/
/* Name: Kim McLeod
 * Date: 7.1.15
 * Solution description: create array of 20 random values, print, sort, print
 */
 
#include <stdio.h>
#include <stdlib.h>

void sort(int* number, int n){

    /*Sort the given array number , of length n*/
    int i, j, temp;
    for(i = 0; i < n - 1; ++i)
    {   
        for(j = 0; j < n - 1 - i; ++j)
        {
            if(number[j] > number[j + 1])
            {
                temp = number[j + 1];
                number[j + 1] = number[j];
                number[j] = temp;
            }        
        }
    }
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    
    /*Allocate memory for an array of n integers using malloc.*/
    int *hello = malloc(sizeof(int) * n); 
    
    /*Fill this array with random numbers, using rand().*/
    for(int i = 0; i < n; i++)
    {   hello[i] = rand() % 20 + 1; }
            
    /*Print the contents of the array.*/
    printf("\nUnsorted:");
    for(int i = 0; i < n; i++)
    {   printf("%d ", hello[i]); }
    
    /*Pass this array along with n to the sort() function of part a.*/
    sort(hello, n);
    
    /*Print the contents of the array.*/    
    printf("\nSorted:");
    for(int i = 0; i < n; i++)
    {   printf("%d ", hello[i]); }
    
    free(hello);
    return 0;
}
