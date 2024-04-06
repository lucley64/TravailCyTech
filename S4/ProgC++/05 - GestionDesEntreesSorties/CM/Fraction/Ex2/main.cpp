#include <iostream>

#include "fraction.h"

using my::fraction, std::cout, std::cin, std::endl;

int main() {

    fraction f;

    cout << "Enter fraction: " << endl;
    cin >> f;

    cout << "You entred the fraction: " << f << endl;

    cout << "Writing into file fraction.txt" << endl;
    f.write_in_file("../fraction.txt");

    exit(EXIT_SUCCESS);
}
