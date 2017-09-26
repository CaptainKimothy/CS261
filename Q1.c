/* CS261- Assignment 1 - Q.1*/
/* Name: Kim McLeod
 * Date: 7.1.15
 * Solution description: create 10 student structures, assign a score and
 * unique ID to each. Print IDs and scores, in ascending ID order
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

struct student{
	int id;
	int score;
};

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student *students = malloc(sizeof(struct student) *10);
    
     /*return the pointer*/
    return students;
}

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/


    /* I had a hard time making sure the entered ID values were unique. 
     * I used stackoverflow for help with this section*/

    int count = 0;     
    while(count < 10)
    {  
       int num = rand() % 10 + 1; 
       bool unique = true;

       for(int j = 0; j < 10; ++j)
       {
             
             if(num == students[j].id)
             {  unique = false;
		break; 
	     } 
       }
         if(unique)
	 { students[count++].id = num; } 
    }

    for(int i = 0; i < 10; i++)
    {  students[i].score = rand() % 100 + 0; }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/


    /* because the IDs were random, I needed to sort the array first, and then print it*/
    int i, j, temp;
    for(i = 0; i < 9; ++i)
    {   
        for(j = 0; j < 9 - i; ++j)
        {
            if(students[j].id > students[j + 1].id)
            {
                temp = students[j + 1].id;
                students[j + 1].id = students[j].id;
                students[j].id = temp;
            }        
        }
    }
    
    for(i = 0; i < 10; i++)
    {    printf("%d %d\n", students[i].id, students[i].score); }
    
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int min, max, sum;
    max = 0;
    min = 100;
    sum = 0;
    double average;
    
    for(int i = 0; i < 10; i++)
    {
       if(students[i].score < min)
       {
           min = students[i].score;
       }
       
       if(students[i].score > max)
       {
           max = students[i].score;
       }
       
       sum += students[i].score;
    }
    average = sum/10;
    printf("\nMinimum Score: %d\n Maximum Score: %d\n Average Score: %g\n", min, max, average);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    if(stud != NULL)
    {
        free(stud);
    }   
}

int main(){

    struct student* stud = NULL;

    /*call allocate*/
    stud = allocate();

    /*call generate*/
    generate(stud);

    /*call output*/
    output(stud);

    /*call summary*/
    summary(stud);

    /*call deallocate*/
    deallocate(stud);

    return 0;
}
