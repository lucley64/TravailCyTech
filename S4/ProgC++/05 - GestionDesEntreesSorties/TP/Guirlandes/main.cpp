#include <iostream>
#include <fstream>


#include "garland.h"

using my::garland, my::light;
using std::cin, std::cout, std::endl;

int main() {
    cout << "Reading from garland.txt" << endl;
    garland g = garland::from_file("../garland.txt");


    g.toggle();
    cout << "Your garland: " << g  << endl;

    cout << "Saving into marketing.txt" << endl;
    g.save_to_file("../marketing.txt");


     exit(EXIT_SUCCESS);
}
