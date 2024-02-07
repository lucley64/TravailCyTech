#include <iostream>

#include "fraction.h"

int main() {
    const fraction f1;
    const fraction f2(10);
    const fraction f3(3, 7);

    const fraction f4(5, 6);

    std::cout << f4 << std::endl;

    exit(EXIT_SUCCESS);
}
