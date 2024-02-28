#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// structure of an undirected graph 
struct edge	 
{ 
 // vertices 
 int vertex1;
 int vertex2;	
}; 

struct graph
{
 int n_vertex;
 int n_edges;
 struct edge *list_of_edges;
};

struct graph *readgraph(char *filename)
{
 FILE *fd;
 struct edge *list_of_edges;
 struct graph *G;
 int vertex1,vertex2;
 int i,no_of_edges,no_of_vertices;

 printf("Reading file %s\n",filename);

 fd=fopen(filename,"r");
 if(fd == NULL){
	perror("Error opening the file.\n");
	exit(-1);
 } 

 /** Complete here  **/

 

 printf("V = %d  E = %d\n",G->n_vertex,G->n_edges);

 return G;

}



int main(int argc, char **argv)
{
 int i;
 int *degree;
 double start_time, run_time;
 struct graph *G;

 if (argc != 2){ 
    printf("Please enter filename containing the graph structure.\n");
    exit(0);
 }
 
 G = readgraph(argv[1]); 

 /** Complete **/ 

}


