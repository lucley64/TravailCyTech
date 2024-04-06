//
// Created by cytech on 05/03/24.
//

#include "triangle.h"

triangle::triangle(const int width, const int height): polygon(width, height) {
}

double triangle::get_area() const {
    return height * width / 2.0;
}
