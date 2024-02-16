# include <omp.h>
# include <stdio.h>
# include <stdlib.h>

int main (int argc,char *argv[]) {

   omp_set_num_threads(4);

   if (argc != 3){
	printf("Wrong number of parameters\n");
	exit(0);
   }

   int a = atoi(argv[1]);
   int b = atoi(argv[2]);

   # pragma omp parallel if(a > b)
    {
	int id = omp_get_thread_num();
	printf("I am thread %d\n",id);
    }

    return 0;
}

