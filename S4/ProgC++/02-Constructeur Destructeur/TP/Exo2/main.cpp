#include <iostream>

#include "garland.h"
#include "light.h"

void first() {
    light l;
    std::cout << l << std::endl;
    l.toggle();
    std::cout << l << std::endl;
}

void second() {
    std::cout << "Enter number of lights: ";
    int nb;
    std::cin >> nb;

    const garland g(nb);

    std::cout << g << std::endl;
    g.toggle();
    std::cout << g << std::endl;
}

int main() {
    first();
    second();
    exit(EXIT_SUCCESS);
}
