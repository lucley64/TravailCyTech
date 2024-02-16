# include <omp.h>
# include <stdio.h>

int main () { //Warning! it might show race conditions
 omp_set_num_threads(4);

 int a = 2;
 int b = 3;

 # pragma omp parallel firstprivate(a) shared(b)
 {
   int id = omp_get_thread_num();

   printf("Thread %d. a: %d. b: %d\n",id,a,b);
   a++; b++;
   printf("Thread %d. a++: %d. b++: %d\n",id,a,b);
 }

 printf("Master. a: %d. b: %d\n",a,b);

 return 0;
}

