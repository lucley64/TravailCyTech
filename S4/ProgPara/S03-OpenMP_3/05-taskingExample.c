#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) 
{
  #pragma omp parallel
  {
   #pragma omp single nowait
   {
      printf("An ");
      #pragma omp task
      {printf("engineering ");}
      #pragma omp task
      {printf("student ");}
   }
  }

   printf("\n");
   return(0);
}
