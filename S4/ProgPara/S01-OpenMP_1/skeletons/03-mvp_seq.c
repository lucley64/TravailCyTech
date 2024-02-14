/* Matrix-vector product A*X=Y
Each thread handles a row in the matrix,
so there will be as many threads as rows.
*/
#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define TOL  0.001

int main(int argc, char **argv)
{
	int M, N;   /* A[M][N], X[N], Y[N] */
	int i,j;
	double *A, *X, *Y, tmp;
	double aval,xval,yval;
	double err, errsq;
	double start_time, run_time;
	int tid;

	M = 10000;
	N = 10000;
	aval = 3.0;
	xval = 2.0;

	
        A = (double *)malloc(M*N*sizeof(double));
        X = (double *)malloc(N*sizeof(double));
        Y = (double *)malloc(M*sizeof(double));

	/* Initialise matrix */

	for (i=0; i<M; i++)
		for (j=0; j<N; j++)
			*(A+(i*N+j)) = aval; 

	/* Initialise arrays */

	for (i=0; i<N; i++){
		*(X+i) = xval; 
	}

	for (i=0; i<M; i++){
		*(Y+i) = 0.0;
	}



	//Start measuring the execution time here 

	/* Calculate the matrix-vector product here */ 

	//Stop measuring the execution time here 

	
	printf("\nTime to complete the matrix-vector product: %lf\n",run_time);
	
	/* Check results */
	yval = aval*xval*(double)N;	
	errsq = 0.0; 
	for (i=0; i<M; i++){
	   err = Y[i] - yval; 
	   errsq += err * err;
	}
	
	if (errsq > TOL) 
		printf("\n Errors in multiplication: %f\n",errsq);
	else
		printf("\n The result is correct\n");

}


