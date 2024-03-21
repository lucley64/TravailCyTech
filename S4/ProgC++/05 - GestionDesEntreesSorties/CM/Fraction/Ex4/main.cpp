#include <iostream>

#include "fraction.h"

using my::fraction, std::cout, std::cin, std::endl;

int main() {


    cout << "Reading frraction from fraction.txt" << endl;
    fraction f = fraction::from_file("../fraction.txt");

    cout << "Fraction: " << f << ", decimal: " << f.decimal() << endl;

    cout << "Enter fraction: " << endl;
    cin >> f;

    cout << "You entred the fraction: " << f << ", decimal: " << f.decimal()  << endl;

    cout << "Writing into file fraction.txt" << endl;
    f.write_in_file("../fraction.txt");

    exit(EXIT_SUCCESS);
}
