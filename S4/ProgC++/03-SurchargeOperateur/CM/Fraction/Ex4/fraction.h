//
// Created by cytech on 07/02/24.
//

#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>


class fraction {
    int numerator;
    int denominator;

    void simplify();

public:
    explicit fraction(int n = 0, int d = 1);
    fraction(double d);

    ~fraction();

    double decimal() const;

    fraction operator*(const fraction& f) const;
    fraction operator*(int i) const;
    fraction operator*=(const fraction& f);
    friend fraction operator *(int i, const fraction& f);

    fraction operator+(const fraction& f) const;
    fraction operator+(int i) const;
    fraction operator+=(const fraction& f);
    friend fraction operator +(int i, const fraction& f);

    fraction operator-(const fraction& f) const;
    fraction operator-(int i) const;
    fraction operator-=(const fraction& f);
    friend fraction operator -(int i, const fraction& f);

    fraction operator/(const fraction& f) const;
    fraction operator/(int i) const;
    fraction operator/=(const fraction& f);
    friend fraction operator /(int i, const fraction& f);

    friend std::ostream& operator <<(std::ostream& out, const fraction& f);
};


#endif //FRACTION_H
