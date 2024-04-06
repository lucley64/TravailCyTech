# include <omp.h>
# include <stdio.h>

const int SIZE = 12;
void showArray(double *M);

int main () { 
 omp_set_num_threads(4);
 int i,id;
 double A[SIZE];

 #pragma omp parallel private(id)
 {
  id=omp_get_thread_num();

  #pragma omp for 
  for (i=0; i<SIZE; i++)
    A[i] = id + 1.0;

  #pragma omp single 
  {
     printf("Before... \n");
     showArray(A);
  }

  #pragma omp for ordered
  for (i=1; i<SIZE; i++)
  {
    /* More code here... */

    #pragma omp ordered
    {
      A[i] /= A[i-1];
    }
  }
 }

 printf("After... \n");
 showArray(A); 
 return 0;
}

void showArray(double *M)
{
 int i;
 for (i=0;i < SIZE; i++)  
   printf("| %2.2lf",M[i]);

 printf("|\n");

}
