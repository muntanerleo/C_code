#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define maxstring 150

//Leonardo Muntaner
//09/1/2021
//Program 0:  Found in the Shuffle (Strings)

// This function is used to determine the longest same suit sequence
int samesuit(char cards[])
{
    int i = 1, count = 1, max = 3;

    while(max < 105)
    {
        if(cards[max] == cards[max-2])
        {
            count = count + 1;
        }
        else
        {
            count = 1;
        }
        //largest variable stores here 
        if(i < count)
            {
                i = count;
            }
            max = max + 2;
    }
    return i; 
}

// This function is used to determine the longest ascending sequence
int LongestAscendingSequence(char cards[])
{
    int largestVal = 1;
    int count = 1;
    int max = 2;
  
    // loop to check if 2 cards are in ascending sequence
    while(max < 105)
    {   
        char check1 = cards[max-2];
        char check2 = cards[max];
        
        if(check1 == 'J'){
            if (check2 == 'Q')
            count = count + 1;
        }
        else if(check1 == 'Q'){
            if (check2 == 'K')
            count = count + 1;
        }
        else if(check1 == 'K'){
            if (check2 == 'A')
            count = count + 1;
        }
        else if(check1 == 'K'){
            if (check2 == 'A')
            count = count + 1;
        }
        else if(check1 == 'A'){
            if (check2 == '2')
            count = count + 1;
        }
        else if(check1 == 'T'){
            if (check2 == 'J')
            count = count + 1;
        }
        else if(check1 == '9'){
            if (check2 == 'T')
            count = count + 1;
        }
        else
            count = 1;
        
        // Store the largest value in this variable
        if(largestVal < count)
             largestVal = count;
        
            
        max = max + 2;
    }
   
    // return the largest value
    return largestVal;
}

int main()
{
    int numOfCases; 
    int longSameSuit; 
    int longAscendingSuit;

    char cards[maxstring], string1[maxstring], string2[maxstring];

    printf("How many test cases would you like to run?");
    //get number of test cases
    scanf("%d", &numOfCases);

    while(numOfCases > 0)
    {
        //get input from user
        scanf("%s", string1);
        scanf("%s", string2);

        //copy input from user to cards string
        strcpy(cards, string1);
        strcat(cards, string2);

        
         //Print the length of longest same suit sequence and the length of longest ascending sequence.
        printf("%d %d\n", samesuit(cards), LongestAscendingSequence(cards));

        numOfCases--;
    }

    return 0;
}