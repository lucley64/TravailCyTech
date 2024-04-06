/* Matrix-vector product A*X=Y
Each thread handles a row in the matrix,
so there will be as many threads as rows.
*/
#include <malloc.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

double f(int x);

int main(const int argc, char** argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <precision>", argv[0]);
        exit(EXIT_FAILURE);
    }

    const size_t N = atoi(argv[1]);


    double x = 0;
    for (int n = 0; n < N; n++) {
        double z = 1.0 / (2 * n + 1);
        if (n % 2 == 1) {
            z *= -1;
        }
        x = (x + z);
    }
    const double pi = 4 * x;
    printf("The value of pi is: %f", pi);

    exit(EXIT_SUCCESS);
}


double f(const int x) {
    return 4 / (1 + pow(x, 2));
}