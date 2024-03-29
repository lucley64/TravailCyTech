#include <iostream>

#include "fraction.h"

namespace my {
    template<typename T>
    T min(const T& a, const T& b) {
        return (a < b ? a : b);
    }
}

using my::fraction, std::cout, std::endl;;

int main() {

    const fraction fraction1(5, 2);
    const fraction fraction2(8, 5);

    const auto minimum = my::min(fraction1, fraction2);

    cout << "The minimum between " << fraction1 << " and " << fraction2 << " is: " << minimum << endl;

    return 0;
}
