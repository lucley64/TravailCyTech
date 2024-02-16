# include <omp.h>
# include <stdio.h>

int main () { 
 omp_set_num_threads(4);

 int nthreads, tid;
 
 #pragma omp parallel private(nthreads, tid)
 {
    tid = omp_get_thread_num();
    printf("Hola! I am thread = %d\n", tid);
 
    if (tid == 0) // If I am the master
    {
       nthreads = omp_get_num_threads();
       printf("Number of threads = %d\n", nthreads);
    }
 }
}


