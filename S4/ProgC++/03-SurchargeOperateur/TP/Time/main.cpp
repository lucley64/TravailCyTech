#include <iostream>

#include "time.h"

int main() {
    const my::time t1(15, 12, 6);
    my::time t2(15, 12, 6);

    std::cout << t2 << std::endl;

    std::cout << (t2 == t1) << std::endl;


    t2++;

    std::cout << t2 << std::endl;

    std::cout << (t2 == t1) << std::endl;

    std::cout << (t2 > t1) << std::endl;



    exit(EXIT_SUCCESS);
}
