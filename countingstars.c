#include <stdio.h>

#define NUM_MOVES 4
#define MAX 100

// Valid movements for floodfill.
const int DX[] = {-1,0,0,1};
const int DY[] = {0,-1,1,0};

void floodfill(char bitmap[][MAX+1], int rows, int cols, int x, int y, char oldfill, char newfill) 
{

   // Deal with out of bounds.
   if (x < 0 || x >= rows || y < 0 || y >= cols)
      return;

   // Not the character we're filling.
    if (bitmap[x][y] != oldfill)
      return;

   // Fill this slot with the new character.
   bitmap[x][y] = newfill;

   // recursion function
   int i;
   for (i = 0; i < NUM_MOVES; i++)
      floodfill(bitmap, rows, cols, x+DX[i], y+DY[i], oldfill, newfill);
}

//function that calculates the stars using floodfill
int solve(char bitmap[][MAX+1], int rows, int cols) 
{

   int numstars = 0;

   //go through the grid and look for char
   for(int i = 0; i < rows; i++)
   {
      for(int j = 0; j < cols; j++)
      {
         if(bitmap[i][j]=='-')
         {
            numstars++;
            floodfill(bitmap, rows, cols, i, j, '-', '#');
         }
      }
   }

   return numstars;
}

int main() 
{
   //m for rows and n for cols
   int rows, cols;
   
   int count = 0;
   
   // Go through each case.
   while(scanf("%d%d", &rows, &cols)!=EOF)
   {
      // Note that the dimensions make room for the null character.
      char map[MAX][MAX+1];

      int i;
      
      // Read in the map, one line at a time.
      for (i=0; i<rows; i++)
         scanf("%s", map[i]);

      int numStars = 0;
      numStars = solve(map, rows, cols);

      count++;

      //print the cases
      printf("Case %d: %d\n", count, numStars);
   }

   return 0;
}