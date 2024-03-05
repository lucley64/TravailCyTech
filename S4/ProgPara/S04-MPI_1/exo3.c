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
    int* arr = malloc(np * sizeof(int));
    int recv;
    if (myid == ROOT) {
        srand(time(NULL));
        arr = gen_array(arr, np);
        print_array(arr, np);
    }
    MPI_Scatter(arr, 1, MPI_INT, &recv, 1, MPI_INT, ROOT, MPI_COMM_WORLD);
    free(arr);
    printf("proc %d received the value %d\n", myid, recv);
}

int main(int argc, char* argv[]) {
    int myid, np;
    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);
    run(myid, np);

    MPI_Finalize();
    return 0;
}
