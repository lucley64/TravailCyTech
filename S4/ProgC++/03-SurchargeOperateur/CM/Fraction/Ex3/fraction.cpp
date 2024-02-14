//
// Created by cytech on 07/02/24.
//

#include "fraction.h"

fraction::fraction(const int n, const int d) : numerator(n), denominator(d) {
}

fraction::~fraction() = default;

fraction fraction::operator*(const fraction& f) const {
    return fraction(numerator * f.numerator, denominator * f.denominator);
}

fraction fraction::operator*(int i) const {
    return fraction(numerator * i, denominator);
}


fraction fraction::operator*=(const fraction& f) {
    numerator *= f.numerator;
    denominator *= f.denominator;
    return *this;
}


std::ostream& operator<<(std::ostream& out, const fraction& f) {
    out << "fraction: " << f.numerator << "/" << f.denominator;
    return out;
}

fraction operator*(const int i, const fraction& f) {
    return fraction(i * f.numerator, f.denominator);
}
