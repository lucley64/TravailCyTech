// Compile with gcc -fopenmp -o 02-exercise 02-exercise.c 
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define N 12
#define NTH 4

double randomFloat();

int main()
{
    double arr[N];
    double max_val=0.0;
    int i,tid,begin,end;

    //Set the number of threads...
    
    // Array initialisation
    for( i=0; i<N; i++)
        arr[i] = randomFloat();

    //Create parallel region
    #pragma omp .....
    {
      tid=omp_get_thread_num();
      begin = tid*(N/NTH);  //Suppose N is divisible by the number of threads.
      end = begin + N/NTH;
	
      /* Find out the maximum value */ 	



    } //end parallel region

    printf("\nmax_val = %f\n", max_val);
}

/* Generates a double value between 0 and 1 */
double randomFloat()
{
    double random_value;
    random_value = (double)rand()/RAND_MAX;
    return random_value;
}
