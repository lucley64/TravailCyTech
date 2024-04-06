#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define N 5

double ** init_matrix() {
    double ** matrix;
    matrix = malloc(N * sizeof(double));
    if (matrix == NULL) {
        exit(-1);
    }
    for (int i = 0; i < N; i++) {
        matrix[i] = malloc(N * sizeof(double));
        if (matrix[i] == NULL) {
            exit(-1);
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = i + j;
        }
    }
    return(matrix);
}

void print_matrix_values(double ** matrix) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Value of matrix[%d][%d]: %f\n", i, j, matrix[i][j]);
        }
    }
}

int main (int argc, char *argv[]) {
    int idTask;
    int nbTasks;
    int nbWorkers;
    int rc;

    double ** matrixA;
    double ** matrixB;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &idTask);
    MPI_Comm_size(MPI_COMM_WORLD, &nbTasks);
    if (nbTasks < 2) {
        printf("Need at least two MPI tasks. Quitting...\n");
        MPI_Abort(MPI_COMM_WORLD, rc);
        exit(1);
    }
    nbWorkers = nbTasks - 1;

    matrixA = init_matrix();
    matrixB = init_matrix();

    // if (idTask == 0) {
    //     matrixA = init_matrix();
    //     matrixB = init_matrix();
    // }

    // print_matrix_values(matrixA);

    MPI_Bcast(*matrixA, N * N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    if (idTask != 0) {
        printf("test : %f\n", matrixA[0][0]);

    }
    MPI_Finalize();

    return(EXIT_SUCCESS);
}