#include <iostream>

#include "time.h"

int main() {
    const my::time t1(15, 12, 6);
    my::time t2(15, 12, 6);

    std::cout << t2 << std::endl;

    ++t2;



    exit(EXIT_SUCCESS);
}
