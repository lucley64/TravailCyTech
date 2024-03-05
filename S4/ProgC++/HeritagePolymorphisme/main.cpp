#include <iostream>
#include <vector>

#include "rectangle.h"
#include "triangle.h"

int main() {
    const std::vector<const polygon*> polygons{
        new rectangle(4, 5),
        new triangle(4, 5),
    };

    std::for_each(polygons.begin(), polygons.end(), [](const polygon* p) { std::cout << p->get_area() << "\n"; });
    std::cout << std::endl;

    exit(EXIT_SUCCESS);
}
