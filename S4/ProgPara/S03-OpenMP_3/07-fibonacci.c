#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

long fib(int n);

int main (int argc, char **argv) { 
 omp_set_num_threads(2);

 if (argc < 2){ 
    printf("No enough parameteres. Enter fib n value.\n");
    exit(0);
 }
 int n = atoi(argv[1]);

 #pragma omp parallel 
 {
   #pragma omp single nowait
   {
    long total = fib(n);
    printf("fib(%d): %ld\n",n,total);
   }
 }
}

long fib(int n) 
{
  if (n < 2){
   return n;
  }

  long x, y, z;
  #pragma omp task shared(x)
  {
   x = fib(n-1);
  }

  #pragma omp task shared(y)
  {
   y = fib(n-2);
  }

  #pragma omp taskwait
  z = x + y;
  return z;
}
