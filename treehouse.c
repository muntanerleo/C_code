#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 8

//this struct stores the coordinates for the X and Y (tree)
typedef struct coordinates
{
  int x;
  int y;
}coordinates;

//function that calculates and finds the minimum possible sum of distances between each tree in the pairs
float calcDist(int numPairs,int perm[], coordinates*coordinates)
{
  //(float sum = 0;) will store the sum of the calculated distance
  float sum = 0;
 
  for(int i = 0; i < 2*numPairs; i+=2)
  {
    float squareDist = pow((coordinates[perm[i]].x - coordinates[perm[i+1]].x),2) + pow((coordinates[perm[i]].y - coordinates[perm[i+1]].y), 2);

    sum += sqrt(squareDist);
  }
  return sum;
}

// Prints all permutations
float PermMaker(coordinates *coordinate,int perm[], int used[], int k, int n)
{
  if(k == (2*n))
  {
    return calcDist(n, perm, coordinate);
  }

  if (k % 2 == 0)
  {
    //keeps track of the min rope length
    float min = 1000000;

    // "i" represents the value we are trying in slot k
    for(int i = perm[k - 2] + 1; i < (2 * n); i++)
    {
      if(!used[i])
      {
        perm[k] = i;
        used[i] = 1; //mark "i" as used for the future
        float value = PermMaker(coordinate, perm, used, k+1, n);

        if(value < min)
        {
          min = value;

        }
        used[i] = 0;
      }
    } 
    return min;
  }

  else
  {
    //keeps track of the min rope length
    float min = 1000000;

    // "i" represents the value we are trying in slot k
    for(int i = 1; i < (2*n); i++)
    {
      if(!used[i])
      {
        perm[k] = i;
        used[i] = 1; //mark "i" as used for the future
        float value = PermMaker(coordinate, perm, used, k+1, n);

        if(value < min)
        {
          min = value;

        }
        used[i] = 0;
      }
    } 
    return min;
  }
}

int main ()
{
  int testCase;
  scanf("%d", &testCase);
  
  // loops through the test cases the user inputs
  for(int i = 0; i < testCase; i++)
  {
    //number of pairs
    int numPairs;
    scanf("%d", &numPairs);

    //create array of structs 
    coordinates* coordinate = calloc((2*numPairs), sizeof(coordinates));

    //gets input from the struct (coordinates)
    for(int i = 0; i < 2*numPairs; i++)
    {
      scanf("%d %d", &coordinate[i].x, &coordinate[i].y);
    }

    int perm[2 * MAX];
    int used[2 * MAX];
    
    for (int i = 0; i < 2*MAX; i++)
    {
      used[i] = 0;
    }

    perm[0] = 0;
    //puts the input into the permutation function
    float minimum = PermMaker(coordinate, perm, used, 1, numPairs);
    printf("%.3f\n", minimum);

    free(coordinate);
  }
  
  return 0;
}