#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

int* gen_array(size_t n);

long sum_elems(const int* start, const int* end, long count);

int main(const int argc, const char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <N>\n", argv[0]);
        exit(EXIT_FAILURE);
    }


    const size_t n = atoi(argv[1]);
    srand(time(NULL));
    int* array = gen_array(n);
    // printf("[");
    // for (const int* i = array; i != array + n - 1; i++) {
    //     printf("%d,", *i);
    // }
    // printf("%d]\n", array[n - 1]);

    const double start = omp_get_wtime();
    const long count = sum_elems(array, array + n, 0);
    const double end = omp_get_wtime();

    printf("Sum of elements: %ld.\n", count);
    printf("Time taken for computation: %f.\n", end - start);

    free(array);
    exit(EXIT_SUCCESS);
}

int* gen_array(const size_t n) {
    int* array = malloc(n * sizeof(int));

    for (int* i = array; i != array + n; i++) {
        *i = (double) rand() / RAND_MAX * 10;
    }

    return array;
}

long sum_elems(const int* start, const int* end, const long count) {
    if (start != end) {
        return sum_elems(start + 1, end, *start + count);
    }
    return count;
}
