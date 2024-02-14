//
// Created by cytech on 07/02/24.
//

#include "fraction.h"

#include <complex>

fraction::fraction(const int n, const int d) : numerator(n), denominator(d) {
    simplify();
}

fraction::fraction(const double d) {
    int count = 0;
    double num = std::abs(d);
    num -= static_cast<int>(num);
    while (num != 0) {
        num *= 10;
        count++;
        num -= static_cast<int>(num);
    }
    numerator = static_cast<int>(d * std::pow(10, count));
    denominator = static_cast<int>(std::pow(10, count));
    simplify();
}

double fraction::decimal() const {
    return static_cast<double>(numerator) / denominator;
}


void fraction::simplify() {
    int a = numerator, b = denominator;
    while (b != 0) {
        const int r = a % b;
        a = b;
        b = r;
    }
    numerator /= a;
    denominator /= a;
}

fraction::~fraction() = default;

fraction fraction::operator*(const fraction& f) const {
    return fraction(numerator * f.numerator, denominator * f.denominator);
}

fraction fraction::operator*(const int i) const {
    return fraction(numerator * i, denominator);
}


fraction fraction::operator*=(const fraction& f) {
    numerator *= f.numerator;
    denominator *= f.denominator;
    simplify();
    return *this;
}


fraction operator*(const int i, const fraction& f) {
    return fraction(i * f.numerator, f.denominator);
}

fraction fraction::operator+(const fraction& f) const {
    return fraction(numerator * f.denominator + denominator * f.numerator, denominator * f.denominator);
}

fraction fraction::operator+(const int i) const {
    return fraction(numerator + i * denominator, denominator);
}


fraction fraction::operator+=(const fraction& f) {
    numerator = numerator * f.denominator + denominator * f.numerator;
    denominator *= f.denominator;
    simplify();
    return *this;
}


fraction operator+(const int i, const fraction& f) {
    return fraction(i * f.denominator + f.numerator, f.denominator);
}

fraction fraction::operator-(const fraction& f) const {
    return fraction(numerator * f.denominator - denominator * f.numerator, denominator * f.denominator);
}

fraction fraction::operator-(const int i) const {
    return fraction(numerator - i * denominator, denominator);
}


fraction fraction::operator-=(const fraction& f) {
    numerator = numerator * f.denominator - denominator * f.numerator;
    denominator *= f.denominator;
    simplify();
    return *this;
}


fraction operator-(const int i, const fraction& f) {
    return fraction(i * f.denominator - f.numerator, f.denominator);
}

fraction fraction::operator/(const fraction& f) const {
    return fraction(numerator * f.denominator, denominator * f.numerator);
}

fraction fraction::operator/(const int i) const {
    return fraction(numerator, denominator * i);
}


fraction fraction::operator/=(const fraction& f) {
    numerator *= f.denominator;
    denominator *= f.numerator;
    simplify();
    return *this;
}


fraction operator/(const int i, const fraction& f) {
    return fraction(f.denominator * i, f.numerator);
}

std::ostream& operator<<(std::ostream& out, const fraction& f) {
    out << "fraction: " << f.numerator << "/" << f.denominator;
    return out;
}
