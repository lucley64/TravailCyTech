#include <iostream>

#include "fraction.h"

namespace my {
    template<typename T>
    T min(const T& a, const T& b) {
        return (a < b ? a : b);
    }

    template<typename T>
    T mean(const T* start, const T* end) {
        T res{};

        for (const T* i = start; i != end ; ++i) {
            res += *i;
        }

        res = res / (end - start);

        return res;
    }
}

using my::fraction, std::cout, std::endl;;

int main() {

    const auto arr = {
        1, 2, 3, 4, 5
    };


    cout << "The mean is: " << my::mean(arr.begin(), arr.end()) << endl;
    return 0;
}
