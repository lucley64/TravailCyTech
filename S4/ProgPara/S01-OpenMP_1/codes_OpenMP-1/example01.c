# include <omp.h>
# include <stdio.h>

int main () {

   int sharedvar = 1;
   printf(" Hola! I am the master thread :-) \n");

   # pragma omp parallel
    {
	int id = omp_get_thread_num();
	printf("I am thread %d. sharedvar = %d\n",id,sharedvar);
    }
	
    printf(" The master thread ends... \n");
    return 0;
}

