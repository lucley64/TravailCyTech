#include <iostream>

#include "garland.h"

int main() {
    garland my_garland1(1);
    garland my_garland2(1);

    my_garland2.toggle();

    garland my_garland = my_garland1 + my_garland2;

    std::cout << my_garland << std::endl;

    my_garland.toggle();

    std::cout << my_garland << std::endl;

    my_garland *= 5;

    std::cout << my_garland << std::endl;

    my_garland.toggle();

    std::cout << my_garland << std::endl;

    my_garland = my_garland / 3;

    my_garland.turn_off();

    std::cout << my_garland << std::endl;

    my_garland.turn_on();

    std::cout << my_garland << std::endl;

    my_garland1 = 5 * my_garland;

    std::cout << my_garland1 << std::endl;

    my_garland2 = my_garland1 - my_garland;

    std::cout << my_garland2 << std::endl;

    exit(EXIT_SUCCESS);
}
