#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define N 5
#define ROOT 0

double** init_matrix(const int id) {
    double** matrix = malloc(N * sizeof(double *));
    if (matrix == NULL) {
        exit(-1);
    }
    for (int i = 0; i < N; i++) {
        matrix[i] = malloc(N * sizeof(double));
        if (matrix[i] == NULL) {
            exit(-1);
        }
        if (id == ROOT) {
            for (int j = 0; j < N; j++) {
                matrix[i][j] = i + j;
            }
        }
    }
    return matrix;
}

void free_matrix(double** matrix, const size_t size) {
    if (matrix != NULL) {
        for (int i = 0; i < size; ++i) {
            if (matrix[i] != NULL) {
                free(matrix[i]);
            }
        }
        free(matrix);
    }
}

void print_matrix_values(double** matrix) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Value of matrix[%d][%d]: %f\n", i, j, matrix[i][j]);
        }
    }
}

int main(int argc, char* argv[]) {
    int idTask;
    int nbTasks;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &idTask);
    MPI_Comm_size(MPI_COMM_WORLD, &nbTasks);
    if (nbTasks < 2) {
        printf("Need at least two MPI tasks. Quitting...\n");
        MPI_Abort(MPI_COMM_WORLD, -1);
        exit(1);
    }
    int nbWorkers = nbTasks - 1;

    printf("Process %d initializing matrix.\n", idTask);
    double** matrixA = init_matrix(idTask);
    double* matrixB = malloc(N * sizeof(double));

    // if (idTask == 0) {
    //     matrixA = init_matrix();
    //     matrixB = init_matrix();
    // }

    // print_matrix_values(matrixA);

    // MPI_Bcast(matrixA[0], N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (nbWorkers % N == 0) {
        int counts[] = {N, N, N, N, N};
        int dipl[] = {0, 5, 10, 15, 20};
        MPI_Scatterv(matrixA, counts, dipl, MPI_DOUBLE, matrixB, N, MPI_DOUBLE, ROOT, MPI_COMM_WORLD);
    }

    if (idTask != ROOT) {
        printf("test %d : %f\n", idTask, matrixB[0]);
    }
    MPI_Finalize();

    free_matrix(matrixA, N);
    // free_matrix(matrixB, N);
    free(matrixB);
    return (EXIT_SUCCESS);
}
