//
// Created by cytech on 05/03/24.
//

#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "polygon.h"


class triangle final : public polygon{
public:
    triangle(int width, int height);

    [[nodiscard]] double get_area() const override;

    ~triangle() override = default;
};



#endif //TRIANGLE_H
