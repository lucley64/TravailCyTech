#include <iostream>

#include "fraction.h"

using my::fraction, std::cout, std::cin, std::endl;

int main() {

    fraction f;

    cout << "Enter fraction: " << endl;
    cin >> f;

    cout << "You entred the fraction: " << f << endl;

    exit(EXIT_SUCCESS);
}
