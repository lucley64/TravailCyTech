# include <mpi.h>
# include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define MPI_TAG_VALUE 123456
#define ROOT 0

int* gen_array(int* array, const size_t n) {
    if (array != NULL) {
        for (int* i = array; i != array + n; i++) {
            *i = (double) rand() / RAND_MAX * 10;
        }
    }

    return array;
}

void print_array(const int* array, const size_t n) {
    if (array != NULL) {
        printf("[");
        for (const int* i = array; i != array + n - 1; i++) {
            printf("%d,", *i);
        }
        printf("%d]\n", array[n - 1]);
    }
}

void run(const int myid, const int np) {
    for (int i = 0; i < np; ++i) {
        if (myid == i % np) {
            MPI_Send(&myid, 1, MPI_INT, i % np + 1, MPI_TAG_VALUE, MPI_COMM_WORLD);
        }
        else if (myid == i % np + 1) {
            int val;
            MPI_Recv(&val, 1, MPI_INT, MPI_ANY_SOURCE, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Process %d recived %d", myid, val);
        }
    }
}

int main(int argc, char* argv[]) {
    int myid, np;
    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    if (np % 2 == 0) {
        run(myid, np);
    }

    MPI_Finalize();
    return 0;
}
