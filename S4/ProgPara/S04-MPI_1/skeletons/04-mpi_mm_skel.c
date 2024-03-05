/******************************************************************************
* FILE: mpi_mm_skel.c
* DESCRIPTION:  
*   MPI Matrix Multiply - C Version
*   In this code, the master task distributes a matrix multiply
*   operation to numtasks-1 worker tasks.
* AUTHOR: Juan Angel Lorenzo. Adapted from Blaise Barney and Ros Leibensperger, 
*   Cornell Theory Center. 
******************************************************************************/
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


#define NRA 62                 /* number of rows in matrix A */
#define NCA 15                 /* number of columns in matrix A */
#define NCB 7                  /* number of columns in matrix B */
#define MASTER 0               /* taskid of first task */
#define FROM_MASTER 1          /* setting a message type */
#define FROM_WORKER 2          /* setting a message type */
#define TOL  0.001             /* Error tolerance in matrix product */

int main (int argc, char *argv[])
{
int	numtasks,              /* number of tasks in partition */
	taskid,                /* a task identifier */
	numworkers,            /* number of worker tasks */
	source,                /* task id of message source */
	dest,                  /* task id of message destination */
	mtype,                 /* message type */
	rows,                  /* rows of matrix A sent to each worker */
	averow, extra, offset, /* used to determine rows sent to each worker */
	i, j, k, rc;           /* misc */


 double **a,                   /* matrix A[NRA][NCA] to be multiplied */
        **b,                   /* matrix B[NCA][NCB] to be multiplied */
        **c,                   /* result matrix C[NRA][NCB] */
	aval,bval,cval,        /* init values for each matrix */
        err, errsq;            /* error and square error of the matrix product */

MPI_Status status;

MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&taskid);
MPI_Comm_size(MPI_COMM_WORLD,&numtasks);
if (numtasks < 2 ) {
  printf("Need at least two MPI tasks. Quitting...\n");
  MPI_Abort(MPI_COMM_WORLD, rc);
  exit(1);
  }
numworkers = numtasks-1;


/**************************** master task ************************************/
   if (taskid == MASTER)
   {
      printf("mpi_mm has started with %d tasks.\n",numtasks);

	   a = (double**)malloc(NRA*sizeof(double*));
		double *ta = (double *)malloc(NRA * NCA * sizeof(double));	

		for (i=0;i<NRA;i++)
		{
			a[i] = &(ta[i*NCA]);
		}

	   b = (double**)malloc(NCA*sizeof(double*));	
		double *tb = (double *)malloc(NCA * NCB * sizeof(double));	

		for (i=0;i<NCA;i++)
		{
			b[i] = &(tb[i*NCB]);
		}

      aval = 3.0;
      bval = 2.0;

      for (i=0; i<NRA; i++)
         for (j=0; j<NCA; j++)
	    a[i][j]= aval;

      for (i=0; i<NCA; i++)
         for (j=0; j<NCB; j++)
            b[i][j]= bval;


      /* Send matrix data to the worker tasks: */

	/* 1. Calculate how many rows per worker */
	/* 2. For each worker, send:
		 offset, 
		 number of rows, 
		 chunk of a of size "number of rows", 
		 a whole copy of b
	*/ 

      mtype = FROM_MASTER;

      /* Receive results from worker tasks */
      mtype = FROM_WORKER;

	   c = (double**)malloc(NRA*sizeof(double*));
		double *tc = (double *)malloc(NRA * NCB * sizeof(double));	

		for (i=0;i<NRA;i++)
		{
			c[i] = &(tc[i*NCB]);
		}

	/* Receive from each worker:
		offset,
		number of rows to receive,
		chunk of c of size "rows to receive",
	*/


      /* Print results */
      printf("******************************************************\n");
      printf("Result Matrix:\n");
      for (i=0; i<NRA; i++)
      {
         printf("\n"); 
         for (j=0; j<NCB; j++) 
            printf("%6.2f   ", c[i][j]);
      }
      printf("\n******************************************************\n");
      printf ("Done.\n");

      /* Check results */
	cval = aval*bval*(double)NCA;	
	errsq = 0.0; 
	for (i=0; i<NRA; i++)
       	  for (j=0; j<NCB; j++){
	    err = c[i][j] - cval; 
	    errsq += err * err;
	  }
	
	if (errsq > TOL) 
		printf("\n Errors in multiplication: %f\n",errsq);
	else
		printf("\n The result is correct\n");


   }


/**************************** worker task ************************************/
   if (taskid > MASTER)
   {
      mtype = FROM_MASTER;

      /* 
	Receive from master:
	   offset,
	   number of rows
      */ 

      
       // Allocate space for the chunk of a received and for the whole b matrix
	   a = (double**)malloc(rows*sizeof(double*));
		double *t = (double *)malloc(rows * NCA * sizeof(double));	

		for (i=0;i<rows;i++)
		{
			a[i] = &t[i*NCA];
		}

	   b = (double**)malloc(NCA*sizeof(double*));	
		double *tb = (double *)malloc(NCA * NCB * sizeof(double));	

		for (i=0;i<NCA;i++)
		{
			b[i] = &(tb[i*NCB]);
		}

	/* Receive chunk of a and whole b */


	// Allocate space for the chunk of c to calculate 
	   c = (double**)malloc(rows*sizeof(double*));
		double *tc = (double *)malloc(rows * NCB * sizeof(double));	

		for (i=0;i<rows;i++)
		{
			c[i] = &(tc[i*NCB]);
		}

	/* Calculate the matrix product */


	/* Send offset, number of rows and chunk of c to the master*/ 
      mtype = FROM_WORKER;
   }
   MPI_Finalize();
}
