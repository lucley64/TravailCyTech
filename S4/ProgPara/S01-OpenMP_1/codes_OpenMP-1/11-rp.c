# include <omp.h>
# include <stdio.h>
# define R 2
# define C 3

int main () { 
 int b = 0;  //Try with b = 100 instead!
 int a[R][C] = {{1,2,3},{4,5,6}};

 omp_set_num_threads(2);

 # pragma omp parallel reduction(+:b)
 {
   int id = omp_get_thread_num();
   //Try here setting b = 100

   for (int i=0;i<C;i++){
	b = b + a[id][i];
   }
   printf("Thread %d working on line %d of a. b = %d\n",id,id,b);
 }

 printf("Back to master. b = %d\n",b);
 return 0;
}

