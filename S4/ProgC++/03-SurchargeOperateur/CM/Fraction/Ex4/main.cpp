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

    f = 2 / f1;

    std::cout << f << std::endl;

    std::cout << fraction(5.125) << ": " << fraction(5.125).decimal() << std::endl;

    exit(EXIT_SUCCESS);
}