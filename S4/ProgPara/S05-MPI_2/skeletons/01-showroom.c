# include <mpi.h>
# include <stdio.h>
# include <string.h>

#define SIZE 10


void resetArray(int *arr);

int main(int argc , char *argv []) 
{
   int myid,np,i;
   int result = -1;
   char message[SIZE];
   int ids[SIZE] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
   int rxids[SIZE] = {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
   int elements_per_proc;

  
   MPI_Init(&argc, &argv);
   MPI_Comm_rank(MPI_COMM_WORLD, &myid);  
   MPI_Comm_size(MPI_COMM_WORLD, &np);

   /** Broadcast **/
   if (myid == 0) {
	   printf("\n========================================\n");
	   printf(" Starting MPI_Bcast...");
	   printf("\n========================================\n");
   }
   MPI_Barrier(MPI_COMM_WORLD);

   if (myid == 0) 
	strcpy(message, "Hello!"); 
   else  
	strcpy(message, "IamEmpty");

   printf("Before broadcast -- I am rank %d. message: %s\n",myid,message);
   MPI_Bcast(message, SIZE, MPI_CHAR, 0,MPI_COMM_WORLD);
   MPI_Barrier(MPI_COMM_WORLD);
   printf("After broadcast -- I am rank %d. message: %s\n",myid,message);

   /** Scatter **/
   MPI_Barrier(MPI_COMM_WORLD); 
   if (myid == 0) {
	   printf("\nPress any key to continue to MPI_Scatter\n");
	   getchar();
	   printf("========================================\n");
	   printf(" Starting MPI_Scatter...");
	   printf("\n========================================\n");

	   // init ids array by rank 0
	   for (i=0; i<SIZE; i++) ids[i]=i;
	   printf("I am rank %d. ids: ",myid);
	   for (i=0; i<SIZE; i++) printf("%d, ",ids[i]);
	   printf("\n");
   }

   MPI_Barrier(MPI_COMM_WORLD); 
   printf("Before scatter -- I am rank %d. rxids: ",myid);
   for (i=0; i<SIZE; i++) printf("%d, ",rxids[i]);
   printf("\n");

   elements_per_proc = 2;
   MPI_Scatter(ids,elements_per_proc,MPI_INT,rxids,elements_per_proc,MPI_INT,0,MPI_COMM_WORLD);

   MPI_Barrier(MPI_COMM_WORLD);
   printf("After scatter -- I am rank %d. rxids: ",myid);
   for (i=0; i<SIZE; i++) printf("%d, ",rxids[i]);
   printf("\n");


   /** Gather **/
   MPI_Barrier(MPI_COMM_WORLD); 
   if (myid == 0) {
	   printf("\nPress any key to continue to MPI_Gather\n");
	   getchar();
	   printf("========================================\n");
	   printf(" Starting MPI_Gather...");
	   printf("\n========================================\n");

	   printf("\nResetting the ids array to -1...\n");
   }
   MPI_Barrier(MPI_COMM_WORLD); 

   resetArray(ids);
 
   MPI_Gather(rxids,elements_per_proc, MPI_INT, ids, elements_per_proc, MPI_INT, 0,MPI_COMM_WORLD);
   printf("After gather -- I am rank %d. ids: ",myid);
   for (i=0; i<SIZE; i++) printf("%d, ",ids[i]);
   printf("\n");




   /** Allgather **/
   MPI_Barrier(MPI_COMM_WORLD); 
   if (myid == 0) {
	   printf("\nPress any key to continue to MPI_Allgather\n");
	   getchar();
	   printf("========================================\n");
	   printf(" Starting MPI_Allgather...");
	   printf("\n========================================\n");

   }
   MPI_Barrier(MPI_COMM_WORLD); 
  
   MPI_Allgather(rxids,elements_per_proc, MPI_INT, ids, elements_per_proc, MPI_INT, MPI_COMM_WORLD);
   printf("After Allgather -- I am rank %d. ids: ",myid);
   for (i=0; i<SIZE; i++) printf("%d, ",ids[i]);
   printf("\n");

  
 /** Alltoall **/
   MPI_Barrier(MPI_COMM_WORLD); 
   if (myid == 0) {
	   printf("\nPress any key to continue to MPI_Alltoall\n");
	   getchar();
	   printf("========================================\n");
	   printf(" Starting MPI_Alltoall...");
	   printf("\n========================================\n");

   }
   MPI_Barrier(MPI_COMM_WORLD); 
   
   for (i=0; i<SIZE; i++) ids[i] += myid;

   printf("Before Alltoall -- I am rank %d. ids: ",myid);
   for (i=0; i<SIZE; i++) printf("%d, ",ids[i]);
   printf("\n");

   resetArray(rxids);

   MPI_Barrier(MPI_COMM_WORLD);   
   MPI_Alltoall(ids,elements_per_proc, MPI_INT, rxids, elements_per_proc, MPI_INT, MPI_COMM_WORLD);
   printf("After Alltoall -- I am rank %d. rxids: ",myid);
   for (i=0; i<SIZE; i++) printf("%d, ",rxids[i]);
   printf("\n");



   /** Reduce **/
   MPI_Barrier(MPI_COMM_WORLD); 
   if (myid == 0) {
	   printf("\nPress any key to continue to MPI_Reduce\n");
	   getchar();
	   printf("========================================\n");
	   printf(" Starting MPI_Reduce...");
	   printf("\n========================================\n");

   }
   MPI_Barrier(MPI_COMM_WORLD); 

   printf("Before Reduce -- I am rank %d. rxids: ",myid);
   for (i=0; i<SIZE; i++) printf("%d, ",rxids[i]);
   printf("\n");

   MPI_Barrier(MPI_COMM_WORLD); 
   MPI_Reduce(rxids, ids, SIZE, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
   printf("After Reduce -- I am rank %d. rxids: ",myid);
   for (i=0; i<SIZE; i++) printf("%d, ",rxids[i]);
   printf("\n");

   if(myid == 0){
   printf("\nAfter Reduce -- I am rank %d. ids: ",myid);
   for (i=0; i<SIZE; i++) printf("%d, ",ids[i]);
   printf("\n");
   }

   MPI_Finalize();
   return 0;
}

void resetArray(int *arr){
   int i;
   for(i=0; i<SIZE; i++)
	arr[i] = -1;
}
