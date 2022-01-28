#include <stdio.h>
#include <stdlib.h>

/* malloc functions simply allocates a memomery block according to the size specified in the heap and on success it returns
a pointer, pointing to the first byte of the allocated memory. else returns NULL

syntax: (void* )malloc(size_t size)
why void pointer?
malloc doesnt have an idea of what it is pointing to.

it allocates memory requested by the user without knowing the type of data to be stored inside the memory
the void pointer can be typecasted to an appropriate type
ex: int *ptr = (int* )malloc(4)

in this example malloc allocates 4 bytes of memory in the heap and the address of the first bytr is stored in the pointer ptr.
*/

// Main 1 DAM practice
/*int main ()
{
  int i, n; //n is the number entered by the user that will be stored in memory
  
  printf("enter the number of integers: ");
  scanf("%d", &n);
  
  int *ptr = (int *)malloc(n*sizeof(int)); //here i ask malloc to allocate memory for the size of "n" number of integers

  if(ptr == NULL)
  {
    printf("memory not available");
    exit(1);
  }
  
  for(i = 0; i < n; i++)
  {
    printf("enter an integer: ");
    scanf("%d", ptr + i);
  }

  for(i = 0; i < n; i++)
  {
    printf("%d ", *(ptr+1));
  }
  return 0;
}
*/

//Main 2 DAM in simple terms 
/*
int main()
{
  ///dynamic memory
  int *arr = malloc(sizeof(int)*100); //give me space for 100 ints 

  arr[90] = 0xFEEDBEEF;
  arr[101] = 8; //OUT OF BOUNDS!!! THIS IS BAD

  free(arr); //i dont need this memory anymore
  arr = NULL;

  double *darr;
  
  ///is the same as -- darr = malloc(sizeof(double)*100);
  darr = calloc(sizeof(double),100); //calloc takes 2 arguments, the number of elements to allocate space for.
  ///and the size of each element. it also sets the bytes in the block to 0.
  
  darr = realloc(darr, sizeof(double)*500); //realloc allows me to resize the amount of memory needed
  ///it can make blocks bigger or smaller
  
  return 0;
}
*/

//Main 3 pointers
/*
int main()
{
  data_type *pointer_name
  here data type refes to the type of the value that the pointer will point to

  for example:
  int *ptr; -------> points to integer value 

  char *ptr; ------> points to a character value

  float *ptr; -------> points to a float value

  it is important to initialize pointer before use
  one way to initialize a pointer is to assign address of some variable

  int x = 5;
  int *ptr;
  ptr = &x; //address of operator. this assigns the address of x to ptr
  
  printf("%d", *ptr); //here, the "*ptr" is the value of operator
  what "*ptr" says is: go to thr address of object and take what is stored in the object

  //we can also change the value of the object pointed by the pointer
  //for example:
  int x = 10;
  int *ptr = &x;
  //with the help of the derefrence oparator i can change 10 to 4
  
  return 0;
}
*/

//Main 4 2d arrays
/*
int main()
{
  
  the basic form of declaring 2d array is:
  
  data_type name_of_array[x][y];

  where x and y are representing the size of the array

  int arr[4][5]; where 4 is the # of rows and 5 is the # of columns
  this array is allowed to store 20 elements. because 4x5 = 20

  how to access 2d array elements?
  by using row index and column index
  
  how to initialize 2d arrays?
  method 1:
  int a[2][3] = {1,2,3,4,5,6};

  method 2:     row 1     row 2
  int a[2][3] = {{1,2,3}, {4,5,6}};
  
  how to print 2d array elements?
  2d array elemnts can be printed using two nested for loops
  for(int i = 0; i < 2; i++)
  {
    for(int j = 0; j < 3; j++)
    {
      printf("%d", a[i][j]);
    }
  }
  
  return 0;
}
*/

//Main 5 structs pointers and dynsmic arrays
/*struct student 
{
  char name[50];
  int age;
  int roll_number;
  float grades;
};
*/

//function to print out the contents in the struct
/*void print(char name[], int age, int roll, float grades)
{
  printf("%s %d %d %.2f", name, age, roll, grades);
}
*/

int main()
{
  //just like variables, we can pass structure members as arguments to a function
  
  //variable struct student is declared. by using the variable "s1" i can initialize the members inside the struct!
  //struct student s1 = {"Nick", 16, 50, 72.5};
  //print(s1.name, s1.age, s1.roll_number, s1.grades);

  //instead of passing struct members individually, it is a good practice to pass a struct 
  //variable as an argument 

}