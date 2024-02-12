#include <iostream>
#include "pair.h"

int main() {
    int a = 15, b = 16;
    const pair p(a, b);
    const pair q{p};
    std::cout << p << q << std::endl;

    int c = 23, d = 42;
    const auto* hp = new pair(c, d);
    std::cout << *hp << std::endl;
    delete hp;

    return EXIT_SUCCESS;
}
