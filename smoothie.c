#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*Stores one component of a smoothie recipe. The itemID represents the ingredient number and
numParts represents the number of parts of that ingredient.*/
typedef struct item 
{
 int itemID;
 int numParts;
} item;

/*Stores one smoothie recipe. numItems stores the number of different ingredients, itemList will
be a dynamically allocated array of item, where each slot of the array stores one ingredient from
the recipe, and totalParts will equal the sum of the numParts of each ingredient in the smoothie.*/
typedef struct recipe {
 int numItems;
 item* itemList;
 int totalParts;
} recipe;

recipe** smoothieList;
double* amtOfEachItem;

char** readIngredients(int numIngredients)
{
  //dynamically allocate array that reads ingredients
  char array[numIngredients][21];

  char** parts = malloc(numIngredients*sizeof(char*));
  
  for(int i =0; i < numIngredients; i++)
  {
    scanf("%s", array[i]);
    parts[i] = malloc(strlen(array[i]) + 1*sizeof(char));
    
    //copies memory from temp array to main array
    strcpy(parts[i],array[i]);
  }
    return parts;
}

/*Reads in numItems number of items from standard input for a smoothie recipe,
Dynamically allocates space for a single recipe, dynamically allocates an array of
item of the proper size, updates the numItems field of the struct, fills the
array of items appropriately based on the input and returns a pointer to the struct
dynamically allocated.*/
recipe* readRecipe(int numItems)
{
  recipe* readList = malloc(sizeof(recipe));
  
  for(int i = 0; i < numItems; i++)
  {
    scanf("%d %d", &readList->itemList[i].itemID, &readList->itemList[i].numParts);
  }
  return readList;
}

/* Dynamically allocates an array of pointers to
recipes of size numRecipes, reads numRecipes number of recipes from standard input, creates
structs to store each recipe and has the pointers point to each struct,*/
recipe** readAllRecipes(int numRecipes)
{
  int numItems;
  scanf("%d", &numItems);
  readRecipe(numItems);

  return (smoothieList);
}

/* Reads in information from standard input about numSmoothies number of smoothie orders and dynamically
allocates an array of doubles of size numIngredients*/
double* calculateOrder(int numSmoothies, recipe** recipeList, int numIngredients)
{
  double *orderList;
  double *amtOfEachItem = calloc(numIngredients, sizeof(double));

  for(int i = 0; i < numSmoothies; i++)
  {
    int smoothies, poundsSold;
    float totalSmoothies;
    scanf("%d %d", &smoothies, &poundsSold);

    totalSmoothies = (float)poundsSold / (float)recipeList[smoothies]->totalParts;
    int numberValue = recipeList[smoothies]->numItems;

    //storing the total pounds for eac of the items
    for(int i = 0; i < numberValue; i++)
    {
      int id = recipeList[smoothies]->itemList[i].itemID;
      amtOfEachItem[id] = amtOfEachItem[id] + (recipeList[smoothies]->itemList[i].numParts * totalSmoothies);
    }
  }
  return orderList;
}

/* Prints out a list, in ingredient order, of each ingredient, a space and the amount of that
ingredient to order rounded to 6 decimal places. One ingredient per line.*/
void printOrder(char** ingredientNames, double* orderList, int numIngredients)
{
  for(int i = 0; i < numIngredients; i++)
  {
    printf("%s %0.6f", *ingredientNames, *orderList);
  }
}

//all the memory pointed to by ingredientList is freed.
void freeIngredients(char** ingredientList, int numIngredients)
{
  for(int i = 0; i < numIngredients; i++)
  {
    free(ingredientList[i]);
  }
  free(ingredientList);
  
}

//all the memory pointed to by allRecipes is freed.
void freeRecipes(recipe** allRecipes, int numRecipes)
{
  for(int i = 0; i < numRecipes; i++)
  {
    free(allRecipes[i]);
  }
  free(allRecipes);
  
}

int main()
{
  //represents the number of possible smoothie ingredients.
  int numIngredients;
  scanf("%d", &numIngredients);
  
  char** ingredientNames = readIngredients(numIngredients);
  
  int numRecipes;
  scanf("%d", &numRecipes);

  readAllRecipes(numRecipes);

  int numOfSmoothieStores;
  scanf("%d", &numOfSmoothieStores);

  int numSmooth;

  for(int i = 0; i < numOfSmoothieStores; i++)
  {
    printf("Store #%d:", i + 1);
    scanf("%d", &numSmooth);

  }

  recipe** smoothieList;

  double* amtOfEachItem;
  
  return 0;
}