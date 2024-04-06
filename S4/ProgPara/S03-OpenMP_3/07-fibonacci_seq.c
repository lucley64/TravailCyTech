#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

long fib(int n);

int main (int argc, char **argv) { 

 if (argc < 2){ 
    printf("No enough parameteres. Enter fib n value.\n");
    exit(0);
 }
 int n = atoi(argv[1]);

 long total = fib(n);
 printf("fib(%d): %ld\n",n,total);
}

long fib(int n) 
{
  if (n < 2){
   return n;
  }

  long x, y, z;
  x = fib(n-1);

  y = fib(n-2);

  z = x + y;
  return z;
}
