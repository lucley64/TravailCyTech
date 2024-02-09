#include <iostream>

#include "vector.h"

void good_copy1(const my::vector& v1) {
    const my::vector v2 = v1;
    v1[0] = 2;
    std::cout << "v1[0] = " << v1[0] << std::endl;
    std::cout << "v2[0] = " << v2[0] << std::endl;

    v2[0] = 3;
    std::cout << "v1[0] = " << v1[0] << std::endl;
    std::cout << "v2[0] = " << v2[0] << std::endl;
}

void bad_copy2(const my::vector& v1) {
    auto v2 = my::vector(5);
    v2 = v1;
    v1[0] = 2;
    std::cout << "v1[0] = " << v1[0] << std::endl;
    std::cout << "v2[0] = " << v2[0] << std::endl;

    v2[0] = 3;
    std::cout << "v1[0] = " << v1[0] << std::endl;
    std::cout << "v2[0] = " << v2[0] << std::endl;
}

void good_copy2(const my::vector& v1) {
    const auto v2 = my::vector(v1);
    v1[0] = 2;
    std::cout << "v1[0] = " << v1[0] << std::endl;
    std::cout << "v2[0] = " << v2[0] << std::endl;

    v2[0] = 3;
    std::cout << "v1[0] = " << v1[0] << std::endl;
    std::cout << "v2[0] = " << v2[0] << std::endl;
}

int main() {

    my::vector v(5);

    for (size_t i = 0; i < v.get_size(); i++) {
        v[i];
    }

    std::cout << "bad_copy1(v)" << std::endl;
    good_copy1(v);

    std::cout << "bad_copy2(v)" << std::endl;
    good_copy2(v);
    exit(EXIT_SUCCESS);
}
