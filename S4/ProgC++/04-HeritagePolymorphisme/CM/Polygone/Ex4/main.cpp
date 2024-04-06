#include <iostream>

#include "rectangle.h"
#include "triangle.h"

int main() {
    const rectangle rect(5, 3);
    std::cout << "Rectangle area: " << rect.get_area() << std::endl;

    const triangle tri(4, 6);
    std::cout << "Triangle area: " << tri.get_area() << std::endl;

    exit(EXIT_SUCCESS);
}
