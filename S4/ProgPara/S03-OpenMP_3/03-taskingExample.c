#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) 
{
  #pragma omp parallel
  {
      printf("An ");
      printf("engineering ");
      printf("student ");
  }

   printf("\n");
   return(0);
}
