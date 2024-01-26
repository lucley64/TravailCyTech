#include <iostream>
#include <vector>

#include "vector.h"

int main() {
    const my::vector v(12);

    std::cout << v[5] << std::endl;

    v[5] = 5;

    std::cout << v[5] << std::endl;

    exit(EXIT_SUCCESS);
}
