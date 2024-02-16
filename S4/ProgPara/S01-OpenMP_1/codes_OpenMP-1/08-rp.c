#include <omp.h>
#include <stdio.h>
#define N 12

int fillArray(int, int *);

int main () { 
 omp_set_num_threads(4);
 int id,i;
 int A[N];
 for (i=0;i<N;i++) A[i] = 12;
 
 #pragma omp parallel private(id) shared(A) 
 {
   id=omp_get_thread_num();
   fillArray(id,A);
 }

 printf("| ");
 for (i=0;i<N;i++) 
 {
   printf("%d |",A[i]);
 }
 printf("\n");

 return 0; 
}


int fillArray(int tid,int *array)
{
  int begin,end,nth,chunk;
  nth = omp_get_max_threads();
  chunk = N/nth; 
    //integer division (on purpose)

  printf("Thread %d. Chunk: %d\n",nth,chunk);

  begin = tid*chunk;
  end = begin + chunk;

  for (int i=begin; i<end ;i++) 
     array[i] = tid;
 
  return 0;
}
