# include <omp.h>
# include <stdio.h>


int main () { // This code is wrong!!
   omp_set_num_threads(4);

   int a = 2;
   int b = 3;

   #pragma omp parallel private(a) shared(b)
    {
	int id = omp_get_thread_num();
#pragma omp critical  //Ignore this pragma for now
{
	printf("Thread %d. Before modification a: %d, b: %d\n",id,a,b);

	a++; 
	b++;

	printf("Thread %d. After modification a: %d, b: %d\n",id,a,b);
} 
   }

    printf("Master thread. a: %d. b: %d\n",a,b);
    return 0;
}

