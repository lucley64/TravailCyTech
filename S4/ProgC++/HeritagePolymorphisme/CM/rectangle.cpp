//
// Created by cytech on 05/03/24.
//

#include "rectangle.h"

rectangle::rectangle(const int width, const int height): polygon(width, height) {}

double rectangle::get_area() const {
    return width * height;
}


