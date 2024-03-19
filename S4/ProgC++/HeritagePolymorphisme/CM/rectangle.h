//
// Created by cytech on 05/03/24.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "polygon.h"


class rectangle final : public polygon {
public:
    rectangle(int width, int height);

    [[nodiscard]] double get_area() const override;

    ~rectangle() override = default;
};


#endif //RECTANGLE_H
