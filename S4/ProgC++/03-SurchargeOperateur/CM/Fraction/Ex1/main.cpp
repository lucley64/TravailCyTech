#include <iostream>

#include "fraction.h"

int main() {
    fraction f1(4, 5);
    const fraction f2(3, 11);

    f1 *= f2;

    std::cout << f1 << std::endl;
    exit(EXIT_SUCCESS);
}
