#include <stdio.h>
#include <stdlib.h>

/*
Recursion:
recursion is a process in which a function calls itself directly or indirectly

for example:
int fun()
{
  ...
  fun(); inside if the function "fun" we are calling fun again!
}

remember that base condition is the one which doesnt require to call the
same function again and it helps in stopping the recursion

*/

//practice: calculate the factorial of a number 
//1. divide the problem into smaller sub-problems
//2. specify the base condition to stop the recursion

//basic structure of a recursive function
fact(int n)
{
  if(n == 1) //here i specify my base case. (the 2nd step i need to do)
  {
    return 1;
  }

  else //here i specify my recursive procedure (the 1st step i need to do)
  {
    return n * fact(n-1);
  }
}

//write a program to print numbers from 1 to 10 in such a way that when number is odd, add 1
//and when number is even, subtract 1
int n;
void odd()
{
  if(n <= 10)
  {
    printf("%d", n+1);
    n++;
    even();
  }
  return;
}

void even()
{
  if(n <= 10) 
  {
    printf("%d", n-1);
    n++;
    odd();
  }
  return;
}

int main()
{
  int n;
  printf("enter the number: ");
  scanf("%d", &n);
  printf("factorial of a number %d is %d", n, fact(n));

  odd();
}