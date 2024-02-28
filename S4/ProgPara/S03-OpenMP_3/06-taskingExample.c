#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) 
{
 #pragma omp parallel num_threads(2)
 {
  #pragma omp single nowait
  {
    printf("An ");
    #pragma omp task
    {printf("engineering ");}
    #pragma omp task
    {printf("student ");}

    #pragma omp taskwait
    printf("likes to party all the time");
  }
 }
 printf("\n");
 return(0);
}
