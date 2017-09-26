/* CS261- Assignment 1 - Q.5*/
/* Name: Kim McLeod
 * Date: 7.1.15
 * Solution description: Ask user for a word, change word to StIcKy formatting
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
     for(int i = 0; (word[i] != '\0'); i++)
     {
	if((i % 2) == 0)
	{  
	    if(islower(word[i]))
	    { word[i] = toUpperCase(word[i]); }
	}
	
	else
	{ 
	    if(isupper(word[i]))
	    { word[i] = toLowerCase(word[i]); }
        }
     }
}

int main(){
    /*Read word from the keyboard using scanf*/
    char word[128];
    printf("\nPlease enter a word\n");
    scanf("%s", word);
    
    /*Call sticky*/
    sticky(word);

    /*Print the new word*/
    printf("\nHere is the new word: %s\n", word);
    return 0;
}
