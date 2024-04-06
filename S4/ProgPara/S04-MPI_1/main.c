# include <mpi.h>
# include <stdio.h>
#include <stdlib.h>
#include <time.h>

# define MPI_TAG_VALUE 123456
#define ROOT 0

# define NRA 50
# define NCA 100
# define NRB NCA
# define NCB 150

int** gen_array(const size_t nr, const size_t nc) {
    int** array = calloc(nc ,sizeof(int*));

    for (int** i = array; i != array + nr; i++) {
        *i = malloc(nr * sizeof(int));
        for (int* j = *i; j != *i + nc; j++) {
            *j = (double) rand() / RAND_MAX * 10;
        }
    }
    return array;
}


void run(const pid_t myid, const int np) {
    int** A;
    int** B;
    if (myid == ROOT) {
        A = gen_array(NRA, NCA);
        B = gen_array(NRB, NCB);
        const size_t nb_workers = np - 1;
        const size_t npa = NRA / np;
        size_t rest = NRA % np;

        for (int i = 1; i <= nb_workers; ++i) {
            const size_t rows = npa + (rest --);

        }

    }






}

int main(int argc, char* argv[]) {
    pid_t myid;
    int np;
    MPI_Init(&argc, &argv);

    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &myid);

    if (np > 1) {
        run(myid, np);
    } else {
        printf("nop\n");
    }

    MPI_Finalize();
    return 0;
}
