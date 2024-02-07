//
// Created by cytech on 07/02/24.
//

#include "fraction.h"

fraction::fraction(const int n, const int d) : numerator(n), denominator(d) {
}

fraction::~fraction() = default;

std::ostream& operator<<(std::ostream& out, const fraction& f) {
    out << "fraction: " << f.numerator << "/" << f.denominator;
    return out;
}
