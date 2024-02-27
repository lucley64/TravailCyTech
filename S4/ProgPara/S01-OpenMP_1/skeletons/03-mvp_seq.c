/* Matrix-vector product A*X=Y
Each thread handles a row in the matrix,
so there will be as many threads as rows.
*/
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define TOL  0.001

/**
* \brief
We have a matrix of doubles, A (size M r ow s ×N col umns) and a vector X (size N ). Write
a parallel code in OpenMP to calculate the matrix-vector product A ∗ X = Y . Create as
many threads as rows in the matrix so that Thread 0 performs the computation for row
0, Thread 1 for row 1, and so on. Start by writing the sequential code and modify it later
to add the parallelism. Measure and compare the execution times of the sequential and
parallel versions. Use the 03-mvp_seq.c code in the skeletons.zip file.
 */
int main(void) {
    const size_t M = 10000;
    const size_t N = 10000; /* A[M][N], X[N], Y[N] */
    double aval = 3.0;
    double xval = 2.0;


    double* A = malloc(M * N * sizeof(double));
    double* X = malloc(N * sizeof(double));
    double* Y = malloc(M * sizeof(double));

    /* Initialise matrix */

    for (size_t i = 0; i < M; i++) {
        for (size_t j = 0; j < N; j++) {
            A[i * N + j] = aval;
        }
    }

    /* Initialise arrays */

    for (size_t i = 0; i < N; i++) {
        X[i] = xval;
    }

    for (size_t i = 0; i < M; i++) {
        Y[i] = 0.0;
    }


    //Start measuring the execution time here
    double run_time = omp_get_wtime();

    /* Calculate the matrix-vector product here */
    /*
     *  A * X = Y
     *
     *  [[1, 2, 3]  *   [1, 2, 3] =
     *   [4, 5, 6]
     *   [7, 8, 9]]
     *
     *
     */


    // for (size_t i = 0; i < N; ++i) {
    //     for (size_t j = 0; j < M; ++j) {
    //         Y[i] += A[i * N + j] * X[i];
    //     }
    // } // Time to complete the matrix-vector product: 0.354880

    omp_set_num_threads(2);
#pragma omp parallel
    {
        const pid_t tid = omp_get_thread_num();

        size_t start, end;
        if (tid == 0) {
            start = 0;
            end = N/2;
        }
        else {
            start = N/2;
            end = N;
        }

        for (size_t i = start; i < end; ++i) {
            for (size_t j = 0; j < M; ++j) {
                Y[i] += A[i * N + j] * X[i];
            }
        } // Time to complete the matrix-vector product: 0.141743



        // for (size_t j = 0; j < M; ++j) {
        //     Y[tid] += A[tid * N + j] * X[tid];
        // }
    } // Time to complete the matrix-vector product: 0.430618


    //Stop measuring the execution time here
    run_time = omp_get_wtime() - run_time;

    printf("\nTime to complete the matrix-vector product: %lf\n", run_time);

    /* Check results */
    const double yval = aval * xval * (double) N;
    double errsq = 0.0;
    for (size_t i = 0; i < M; i++) {
        const double err = Y[i] - yval;
        errsq += err * err;
    }

    if (errsq > TOL) {
        printf("\n Errors in multiplication: %f\n", errsq);
    } else {
        printf("\n The result is correct\n");
    }


    free(A);
    free(X);
    free(Y);
}
