#include <mpi.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
  int myid, np;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_rank(MPI_COMM_WORLD, &myid);

  printf("I am the node %d of %d\n", myid, np);

  MPI_Finalize();
  return 0;
}
