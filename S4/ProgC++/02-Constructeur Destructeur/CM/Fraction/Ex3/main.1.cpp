#include <iostream>

#include "fraction.h"

int main() {
    std::cout << "Number of fraction to create?" << std::endl;

    int n;
    std::cin >> n;

    auto* tf = new fraction[n];

    for (int i = 0; i < n; ++i) {
        tf[i] = fraction(i, i+1);
        std::cout << tf[i] << std::endl;
    }

    delete[] tf;

    exit(EXIT_SUCCESS);
}
