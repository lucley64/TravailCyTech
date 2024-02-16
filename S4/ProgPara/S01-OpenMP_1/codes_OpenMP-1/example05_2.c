# include <omp.h>
# include <stdio.h>

int main () {

   omp_set_num_threads(8);
   printf("How many threads (master): %d \n",omp_get_num_threads());

   # pragma omp parallel num_threads(4)
    {
	int id = omp_get_thread_num();
	printf("I am thread %d \n",id)	;
	printf("How many threads in the parallel region (%d): %d \n\n",id, omp_get_num_threads());
    }
	
    printf(" The master thread ends... \n");
    return 0;
}

