//
// Created by cytech on 07/02/24.
//

#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>


class fraction {
    int numerator;
    int denominator;

public:
    explicit fraction(int n = 0, int d = 1);
    ~fraction();

    friend std::ostream& operator << (std::ostream&out, const fraction&f);
};



#endif //FRACTION_H
