/* CS261- Assignment 1 - Q.4*/
/* Name: Kim McLeod
 * Date: 7.1.15
 * Solution description: create array of students and sort by score (ascending)
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct student{
	int id;
	int score;
};

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/ 
     int i, j, temp;
     for(i = 0; i < n - 1; ++i)
     {   
         for(j = 0; j < n - 1 - i; ++j)
         {
             if(students[j].score > students[j + 1].score)
             {
                 temp = students[j + 1].score;
                 students[j + 1].score = students[j].score;
                 students[j].score = temp;
             }        
        }
     }    
}

int main(){

    /*Declare an integer n and assign it a value.*/
    int n = 12;
 
    /*Allocate memory for n students using malloc.*/
    struct student *students = malloc(sizeof(struct student) *10);

    /*Generate random IDs and scores for the n students, using rand().*/
     
     /* I had a hard time making sure the entered ID values were unique. 
     * I used stackoverflow for help with this section*/

    int count = 0;     
    while(count < 12)
    {  
       int num = rand() % 12 + 1; 
       bool unique = true;

       for(int j = 0; j < 12; ++j)
       {
             
             if(num == students[j].id)
             {  unique = false;
		break; 
	     } 
       }
         if(unique)
	 { students[count++].id = num; } 
    }

    for(int i = 0; i < 12; i++)
    {  students[i].score = rand() % 100 + 0; }


    /*Print the contents of the array of n students.*/
    printf("\nUnsorted: \n");
    for(int i = 0; i < 12; i++)
    {    printf("%d %d\n", students[i].id, students[i].score); }

    /*Pass this array along with n to the sort() function*/
    sort(students, n);

    /*Print the contents of the array of n students.*/
    printf("\n\nSorted by score (ascending):\n");
    for(int i = 0; i < 12; i++)
    {    printf("%d  %d\n", students[i].id, students[i].score); }

    return 0;
}
