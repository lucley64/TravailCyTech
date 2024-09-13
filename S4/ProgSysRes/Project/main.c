#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "PartA/part_a.h"
#include "PartB/part_b.h"

int main(const int argc, const char** argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <part_a|part_b> [args]", argv[0]);
        exit(EXIT_FAILURE);
    }


    if (strcmp(argv[1], "part_a") == 0) {
        part_a(argc, argv);
    } else if (strcmp(argv[1], "part_b") == 0) {
        part_b(argc, argv);
    }

    exit(EXIT_SUCCESS);
}
