//
// Created by cytech on 05/03/24.
//

#ifndef POLYGONE_H
#define POLYGONE_H




class polygon {
protected:
    int width;
    int height;
    polygon(int width, int height);

    [[nodiscard]] virtual double get_area() const = 0;

    virtual ~polygon() = default;
};
#endif //POLYGONE_H
