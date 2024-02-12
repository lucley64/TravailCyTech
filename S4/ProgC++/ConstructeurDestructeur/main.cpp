#include <iostream>

#include "game.h"
#include "garland.h"
#include "light.h"

int main() {

    game g(std::vector<tower>{
        tower("start", std::vector{
            disk(1),
            disk(2),
            disk(3),
            disk(4)}),
        tower("middle"),
        tower("goal")});


    std::cout << g << std::endl;

    g.solve();

    std::cout << g << std::endl;


    exit(EXIT_SUCCESS);
}
