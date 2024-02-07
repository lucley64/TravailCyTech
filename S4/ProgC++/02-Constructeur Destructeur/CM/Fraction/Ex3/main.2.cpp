#include <iostream>

#include "fraction.h"

int main() {
    std::cout << "Number of fraction to create?" << std::endl;

    int n;
    std::cin >> n;

    auto** ppf = new fraction *[n];

    for (int i = 0; i < n; ++i) {
        ppf[i] = new fraction(i, i + 1);
        std::cout << *ppf[i] << std::endl;
    }

    for (int i = 0; i < n; ++i) {
        delete ppf[i];
    }

    delete[] ppf;

    exit(EXIT_SUCCESS);
}
