#include <stdio.h>
#include <stdlib.h>

//Leonardo Muntaner
//10/27/2021
//P4: Scholarly Reader (Sorting)

void merge(int pages[], int first, int middle, int end)
{
    //these two ints find number of elements for both my lists
    int numBooks1 = middle - first + 1;
    int numBooks2 = end - middle;
    
    //allocate the proper amount of space for arrays.
    int *a = (int*)malloc(numBooks1*sizeof(int));
    
    int *b = (int*)malloc(numBooks2*sizeof(int));
    
    int i, j; 
    for (i = 0; i < numBooks1; i++)
        a[i] = pages[first + i];
    
    for (j = 0; j < numBooks2; j++)
        b[j] = pages[middle + 1 + j];
        
    int k = first;
    
    i = 0;  
    j = 0;
    //while loop that copies values into my array
    while(i < numBooks1 && j < numBooks2) 
    {
        if(a[i] <= b[j]) 
        {
            pages[k] = a[i];
            i++; 
        }
        
        else 
        {
            pages[k] = b[j];
            j++; 
        }
        k++;
    }
  
    //both of these while loops copy elements that are leftver
    while(i < numBooks1)
    {
        pages[k] = a[i];
        i++;
        k++;
    }
    
    while(j < numBooks2) 
    {
        pages[k] = b[j];
        j++;
        k++;
    }
    
    free(a);
    free(b);
}

//function that does the sorting using mergesort method
void mergeSort(int pages[], int start, int finish)
{
    //check if the range is more than one element
    if(start < finish) 
    {
        int middle = start + (finish - start) / 2;  //find the middle index
        
        mergeSort(pages, start, middle); //Sort the first half

        mergeSort(pages, middle + 1, finish); //Sort the last half

        merge(pages, start, middle, finish); //Put it all together.
    }
}

//function that prints the max book number without going out of bounds
int maxNumBooks(int pages[], int n, long long maxPageRead)
{
    long long temp = 0; //made the change to long long temp and it worked
    
    //before i had set the int result to long long and that was giving me a bad bug
    int result = 0;
    
    //here i tried a for loop first but then decided to switch it to a while loop.
    //i dont know why but the for loop was throwing some errors
    while(result < n)
    {
        temp += pages[result];
        if(temp > maxPageRead)
            break;
        
        else
            result++;                  
    }
        
    return result;
}

int main()
{
    int testCases;
    scanf("%d", &testCases);
    
     for(int i = 0; i < testCases; i++)
    {
        //max number of books in library and max number of pages to read
        int booksInLib;
        long long maxNumPage;
        scanf("%d %lld", &booksInLib, &maxNumPage);
        
        //makes space for booksInLib array to be stored
        int *pages = (int*)malloc(booksInLib*sizeof(int));
        
        //read and sort the array
        for(int j = 0; j < booksInLib; j++)
        {
            scanf("%d", &pages[j]);
        }
        
        mergeSort(pages, 0, booksInLib-1);
        
        int result = maxNumBooks(pages, booksInLib, maxNumPage);
        
        printf("%d\n", result);
        
        free(pages);
    }
        
    return 0;
}
