// Arup Guha
// 5/6/2020
// Solution for 2018 Benelux Algorithms Contest Problem: A Prize No One Can Win
// To be used for COP 3502 Recitation
// Edited on 7/5/2020 to post for the solution (made it cleaner)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void quicksort(int *numbers, int low, int high);
int partition(int *vals, int low, int high);
void swap(int *a, int *b);
int issorted(int *numbers, int low, int high);
void print(int *numbers, int length);

int main(void)
{

    srand(time(0));

    // Get # of values, max.
    int n, max;
    scanf("%d", &n);
    scanf("%d", &max);

    // Read and sort array.
    int *vals = malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        scanf("%d", vals + i);
    quicksort(vals, 0, n - 1);

    print(vals, n);

    // Find max i such that some of the value there and the previous index is less than or equal to the max allowed.
    int res = 1;
    for (int i = 1; i < n; i++)
    {
        if (vals[i - 1] + vals[i] <= max)
            res = i + 1;
        else
            break;
    }

    // Ta da!
    printf("%d\n", res);

    free(vals);
    return 0;
}

// Returns 1 iff numbers[low..high] is sorted.
int issorted(int *numbers, int low, int high)
{

    // Look for any consecutive terms out of order.
    for (int i = low; i < high; i++)
        if (numbers[i] > numbers[i + 1])
            return 0;

    // If we get here, we are good.
    return 1;
}

// Pre-condition: s and f are value indexes into numbers.
// Post-condition: The values in numbers will be sorted in between indexes s
//                 and f.
void quicksort(int *numbers, int low, int high)
{

    // This is the troublesome case to screen out - specifically, if all the numbers in the
    // range are the same.
    if (issorted(numbers, low, high))
        return;

    // If we get here, we have an unsorted array, so quick sort is safe to call.
    int split = partition(numbers, low, high);
    quicksort(numbers, low, split - 1);
    quicksort(numbers, split + 1, high);
}

// Pre-condition: low and high are valid indexes into values
// Post-condition: Returns the partition index such that all the values
//                 stored in vals from index low to until that index are
//                 less or equal to the value stored there and all the values
//                 after that index until index high are greater than that
//                 value.
int partition(int *vals, int low, int high)
{

    int temp;
    int i, lowpos;

    // Pick a random partition element and swap it into index low.
    i = low + rand() % (high - low + 1);
    swap(&vals[low], &vals[i]);

    // Store the index of the partition element.
    lowpos = low;

    // Update our low pointer.
    low++;

    // Run the partition so long as the low and high counters don't cross.
    while (low <= high)
    {

        // Move the low pointer until we find a value too large for this side.
        while (low <= high && vals[low] <= vals[lowpos])
            low++;

        // Move the high pointer until we find a value too small for this side.
        while (high >= low && vals[high] > vals[lowpos])
            high--;

        // Now that we've identified two values on the wrong side, swap them.
        if (low < high)
            swap(&vals[low], &vals[high]);
    }

    // Swap the partition element into it's correct location.
    swap(&vals[lowpos], &vals[high]);

    return high; // Return the index of the partition element.
}

// Swaps the values pointed to by a and b.
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Prints all the numbers in the array numbers.
void print(int *array, int length)
{

    int i;
    for (i = 0; i < length; i++)
        printf("%d ", array[i]);
    printf("\n");
}