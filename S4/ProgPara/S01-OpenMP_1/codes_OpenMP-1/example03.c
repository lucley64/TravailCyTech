# include <omp.h>
# include <stdio.h>

int main () {
   omp_set_num_threads(8);

   printf(" Hola! I am the master thread :-) \n");

   # pragma omp parallel
    {
	int id = omp_get_thread_num();
	printf("I am thread %d \n",id);
    }
	
    printf(" The master thread ends... \n");
    return 0;
}

