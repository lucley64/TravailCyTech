#include <iostream>

#include "fraction.h"
#include "my_vector.h"

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

    my::vector<int> ints(5);

    ints[0] = 1;
    ints[1] = 2;
    ints[2] = 3;
    ints[3] = 4;
    ints[4] = 5;


    cout << ints << endl;

}
