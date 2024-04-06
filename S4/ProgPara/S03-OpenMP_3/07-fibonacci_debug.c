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

long fib(int n) {
 if (n < 2){
  printf("n < 2 (n==%d). Returning %d\n",n,n);
  return n;
 }

 long x, y, z;
 #pragma omp task shared(x)
 {
  printf("Task 1. tid %d. Calling fib(n-1)=fib(%d) x = %ld\n",omp_get_thread_num(),n-1,x);
  x = fib(n-1);
  printf("Task 1. tid %d. Out of fib(n-1)=fib(%d) x = %ld\n",omp_get_thread_num(),n-1,x);
 }
 #pragma omp task shared(y)
 {
  printf("Task 2. tid %d. Calling fib(n-2)=fib(%d) y = %ld\n",omp_get_thread_num(),n-2,y);
  y = fib(n-2);
  printf("Task 2. tid %d. Out of fib(n-2)=fib(%d) y = %ld\n",omp_get_thread_num(),n-2,y);
 }

 #pragma omp taskwait
 z = x + y;
 printf("tid %d. Returning z=%ld. x=%ld y=%ld. n=%d\n",omp_get_thread_num(),z,x,y,n);
 return z;
}
