// Compile with gcc -fopenmp -o 02-exercise 02-exercise.c
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

#define N 12
#define NTH 4

double randomFloat();

int main() {
    double arr[N];
    double max_val = 0.0;

    //Set the number of threads...
    omp_set_num_threads(NTH);

    srand(time(NULL));

    // Array initialisation
    for (size_t i = 0; i < N; i++) {
        arr[i] = randomFloat();
    }

    //Create parallel region
#pragma omp parallel reduction(max: max_val)
    {
        const pid_t tid = omp_get_thread_num();
        const size_t begin = tid * (N / NTH); //Suppose N is divisible by the number of threads.
        const size_t end = begin + N / NTH;

        /* Find out the maximum value */
        for (size_t i = begin; i < end; ++i) {
            if (arr[i] > max_val) {
                max_val = arr[i];
            }
        }
    } //end parallel region

    printf("max_val = %f\n", max_val);

}

/* Generates a double value between 0 and 1 */
double randomFloat() {
    return (double) rand() / RAND_MAX;
}
