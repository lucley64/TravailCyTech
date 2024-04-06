#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <omp.h>

// structure of an undirected graph
struct edge {
    // vertices
    int vertex1;
    int vertex2;
};

struct graph {
    int n_vertex;
    int n_edges;
    struct edge* list_of_edges;
};

struct graph* read_graph(const char* filename) {
    printf("Reading file %s\n", filename);

    FILE* fd = fopen(filename, "r");
    if (fd == NULL) {
        perror("Error opening the file.\n");
        exit(EXIT_FAILURE);
    }

    struct graph* graph = malloc(1 * sizeof(struct graph));
    char* line = NULL;
    size_t len = 0;
    ssize_t read = getline(&line, &len, fd);
    if (read == -1) {
        perror("Cannot read number of vertices.");
        fclose(fd);
        exit(EXIT_FAILURE);
    }
    graph->n_vertex = atoi(line);

    read = getline(&line, &len, fd);
    if (read == -1) {
        perror("Cannot read number of edges.");
        fclose(fd);
        exit(EXIT_FAILURE);
    }
    graph->n_edges = atoi(line);
    graph->list_of_edges = malloc(graph->n_edges * sizeof(struct edge));

    for (struct edge* e = graph->list_of_edges; getline(&line, &len, fd) != -1 && e != graph->list_of_edges + graph->
                                                n_edges; e++) {
        const char* ptr = strtok(line, " ");
        if (ptr == NULL) {
            perror("Cannot parse file");
        }
        const int x = atoi(ptr);
        ptr = strtok(NULL, " ");
        if (ptr == NULL) {
            perror("Cannot parse file");
        }
        const int y = atoi(ptr);
        e->vertex1 = x;
        e->vertex2 = y;
    }

    fclose(fd);
    printf("V = %d  E = %d\n", graph->n_vertex, graph->n_edges);

    return graph;
}


int main(const int argc, const char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>", argv[0]);
        exit(0);
    }

    struct graph* graph = read_graph(argv[1]);

    const double start = omp_get_wtime();

    int* degrees = calloc(graph->n_vertex, sizeof(int));

#pragma omp parallel
    {
#pragma omp for
        for (const struct edge* e = graph->list_of_edges; e != graph->list_of_edges + graph->n_edges; e++) {
#pragma omp atomic
            degrees[e->vertex1]++;
#pragma omp atomic
            degrees[e->vertex2]++;
        }
    }

    const double end = omp_get_wtime();


    // for (int i = 0; i < graph->n_vertex; ++i) {
    //     printf("vertex %d has a degree of %d.\n", i, degrees[i]);
    // }

    printf("Time taken for the measurment: %f\n", end - start);

    free(degrees);
    free(graph->list_of_edges);
    free(graph);


    exit(EXIT_SUCCESS);
}
