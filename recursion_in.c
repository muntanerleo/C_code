#include <stdio.h>
#include <stdlib.h>

//this function is for factorial 
int fact(int n)
{
  //this case is so easy that we just return it 
  if(n == 0)
    return 1;
  
  //this is the recursive breakdown to solve the problem.
  return fact(n - 1)*n;
}

//this function is for fibonacci
int fib(int n)
{
  if(n < 2)
  return n;

  return fib(n - 1) + fib( n - 2);
}

//function for power. works for both positive and negative exponents
double mypow(double base, int exp)
{
  //flips problem to be a positive exponent
  if(exp < 0)
    return 1.0/mypow(base, -exp);
  
  if(exp == 0)
    return 1;
  
  return mypow(base, exp - 1) * base;
}

void tipChart(int minVal, int maxVal, double percent)
{
  //we do work if there is a valid chart to print 
  if(minVal <= maxVal)
  {
    printf("%d\t%.2lf\n", minVal, minVal*percent/100);
    tipChart(minVal + 1, maxVal, percent);
  }
}

int sumdigits(int n)
{
  if(n == 0) return n;
  return sumdigits(n/10) + (n%10);
}

int main(void)
{
  /*for(int i =0; i <= 12; i++)
    printf("%d! = %d\n",i, fact(i));*/
  
  /*for(int i = -4; i <= 4; i++)
    printf("3 to the power %d is %lf\n", i, mypow(3,i));*/

  //tipChart(10, 50, 15);

  printf("sumd(23445539) = %d\n", sumdigits(2345539));
  return 0;
}