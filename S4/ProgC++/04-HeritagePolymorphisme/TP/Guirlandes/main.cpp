#include <iostream>

#include "garland.h"

int main() {
    garland my_garland1({light(220., .05)});
    garland my_garland2({light()});

    my_garland2.toggle();

    garland my_garland = my_garland1 + my_garland2;

    std::cout << my_garland << ", power consumtion: " << my_garland.get_power() << std::endl;

    my_garland.toggle();

    std::cout << my_garland << ", power consumtion: " << my_garland.get_power() << std::endl;

    my_garland *= 5;

    std::cout << my_garland << ", power consumtion: " << my_garland.get_power() << std::endl;

    my_garland.toggle();

    std::cout << my_garland << ", power consumtion: " << my_garland.get_power() << std::endl;

    my_garland = my_garland / 3;

    my_garland.turn_off();

    std::cout << my_garland << ", power consumtion: " << my_garland.get_power() << std::endl;

    my_garland.turn_on();

    std::cout << my_garland << ", power consumtion: " << my_garland.get_power() << std::endl;

    my_garland1 = 5 * my_garland;

    std::cout << my_garland1 << ", power consumtion: " << my_garland1.get_power() << std::endl;

    my_garland2 = my_garland1 - my_garland;

    std::cout << my_garland2 << ", power consumtion: " << my_garland2.get_power() << std::endl;

    my_garland2.force_turn_on();

    std::cout << my_garland2 << ", power consumtion: " << my_garland2.get_power() << std::endl;


    exit(EXIT_SUCCESS);
}
