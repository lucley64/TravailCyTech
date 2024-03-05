# include <mpi.h>
# include <stdio.h>

# define MPI_TAG_VALUE 123456
	
void run( const int myid) {
   if ( myid == 0) {
      int valtx;
      valtx = 3785;

      MPI_Send(&valtx ,1, MPI_INT ,1, MPI_TAG_VALUE, MPI_COMM_WORLD);
      valtx++;
      MPI_Send(&valtx ,1, MPI_INT ,2, MPI_TAG_VALUE, MPI_COMM_WORLD);
      valtx++;
      MPI_Send(&valtx ,1, MPI_INT ,3, MPI_TAG_VALUE, MPI_COMM_WORLD);
   }
   else { 
      int valrx;
      MPI_Status status;
      MPI_Recv(&valrx ,1, MPI_INT,0, MPI_TAG_VALUE, MPI_COMM_WORLD, &status);
      printf("proc %d received the value %d\n",myid,valrx);
   }
}

int main(int argc , char *argv []) {
   int myid;
   MPI_Init(&argc, &argv);
  
   MPI_Comm_rank(MPI_COMM_WORLD, &myid);
   run(myid);

   MPI_Finalize();
   return 0;
}

