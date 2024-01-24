#include <mpi.h>
#include <stdio.h>
#include <string.h>
#define size 20

int main(int argc, char *argv[]){
  int myid, np, i;
  int tag = 0;
  char msg[size] = "";
  MPI_Status stt;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &np);
  MPI_Comm_rank(MPI_COMM_WORLD, &myid);

  if(myid == 0){
    strcpy(msg,"Hello MPI");
    for(i=1; i<np;i++)
      MPI_Send(msg, size, MPI_CHAR, i, tag, MPI_COMM_WORLD);
  }else
      MPI_Recv(msg, size, MPI_CHAR, 0, tag, MPI_COMM_WORLD, &stt);

  printf("I am node %d: %s\n", myid, msg);
  MPI_Finalize();
}
