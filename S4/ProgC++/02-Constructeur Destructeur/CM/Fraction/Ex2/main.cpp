#include <iostream>

#include "fraction.h"

int main() {
    const fraction* pf = new fraction(7, 5);

    std::cout << *pf << std::endl;

    delete pf;
    

    exit(EXIT_SUCCESS);
}
