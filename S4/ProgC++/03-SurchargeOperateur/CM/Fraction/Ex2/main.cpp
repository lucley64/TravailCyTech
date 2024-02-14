#include <iostream>

#include "fraction.h"

int main() {
    const fraction f1(4, 5);
    const fraction f2(3, 11);
    fraction f = f1 * f2;

    std::cout << f << std::endl;

    f = f1 * f2 * f;

    std::cout << f << std::endl;

    f = f1 * 2;

    std::cout << f << std::endl;


    std::cout << f1 << std::endl;
    exit(EXIT_SUCCESS);
}
