#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char prevWord[21];
    scanf("%s",prevWord);
    int n;
    scanf("%d",&n);
    char **arrayAn;
    char temp[n][21];
    
    //Dynamically allocate 2d character array arrayAn
    arrayAn = malloc(n * sizeof(char*));

    for(int i = 0; i < n; i++) 
    {
         scanf("%s", temp[i]);
         arrayAn[i] = malloc(strlen(temp[i]) * sizeof(char));
         strcpy(arrayAn[i], temp[i]);
    }
    
    //Initialize the array, so all values start at 0
    int freqArray[26];
    
    for(int i = 0; i < 26; i++)
        freqArray[i] = 0;

   //Every time we find a letter, add 1 to that box.
    for(int i = 0; i < n; i++)
    {
      freqArray[arrayAn[i][0] - 'a']++;
    }

    //Find last letter of prevWord
    char lastLetter = prevWord[strlen(prevWord) - 1];

    //This checks if the last letter is in the freqArray. if it is not then it returns "?"
    if(freqArray[lastLetter - 'a']==0)
    {
        printf("?\n");
        
        return 0;
    }

    //These all check for the inputs and the one with the "!" test for when a word is used (like the eagle ex.)
    for(int i = 0; i < n; i++)
     {
        if(arrayAn[i][0] == lastLetter && arrayAn[i][strlen(arrayAn[i]) - 1] == lastLetter)
        {
            freqArray[lastLetter - 'a']--;
        }

        if(arrayAn[i][0] == lastLetter && freqArray[arrayAn[i][strlen(arrayAn[i]) - 1] - 'a'] == 0)
        {
            printf("%s!\n", arrayAn[i]);
            return 0;
        }

        if(arrayAn[i][0] == lastLetter && arrayAn[i][strlen(arrayAn[i]) - 1] == lastLetter)
        {
            freqArray[lastLetter - 'a']++;
        }
     }

    for (int i = 0; i < n; i++)
    {
        if(arrayAn[i][0] == lastLetter && freqArray[arrayAn[i][strlen(arrayAn[i]) - 1] - 'a'] > 0)
        {
            printf("%s\n", arrayAn[i]);
            return 0;
        }
    }

    //frees the 2D array arrayAn
    free(arrayAn);
    
    return 0;
}