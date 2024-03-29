//
// Created by cytech on 07/02/24.
//

#include "fraction.h"

#include <complex>
#include <fstream>

namespace my {
    fraction::fraction(const int n, const int d) : numerator(n), denominator(d) { simplify(); }

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

    fraction::fraction(const fraction& f) : numerator(f.numerator), denominator(f.denominator) { simplify(); }


    double fraction::decimal() const { return static_cast<double>(numerator) / denominator; }


    void fraction::simplify() {
        if (denominator == 0) {
            throw std::logic_error("Error divide by zero");
        }
        int a = numerator, b = denominator;
        while (b != 0) {
            const int r = a % b;
            a = b;
            b = r;
        }
        numerator /= a;
        denominator /= a;
    }

    fraction& fraction::operator=(const fraction& f) {
        return *this;
    }


    fraction fraction::operator*(const fraction& f) const {
        return fraction(numerator * f.numerator, denominator * f.denominator);
    }

    fraction fraction::operator*(const int i) const { return fraction(numerator * i, denominator); }


    fraction fraction::operator*=(const fraction& f) {
        numerator *= f.numerator;
        denominator *= f.denominator;
        return *this;
    }


    fraction operator*(const int i, const fraction& f) { return fraction(i * f.numerator, f.denominator); }

    fraction fraction::operator+(const fraction& f) const {
        return fraction(numerator * f.denominator + denominator * f.numerator, denominator * f.denominator);
    }

    fraction fraction::operator+(const int i) const { return fraction(numerator + i * denominator, denominator); }


    fraction fraction::operator+=(const fraction& f) {
        numerator = numerator * f.denominator + denominator * f.numerator;
        denominator *= f.denominator;
        return *this;
    }


    fraction operator+(const int i, const fraction& f) {
        return fraction(i * f.denominator + f.numerator, f.denominator);
    }

    fraction fraction::operator-(const fraction& f) const {
        return fraction(numerator * f.denominator - denominator * f.numerator, denominator * f.denominator);
    }

    fraction fraction::operator-(const int i) const { return fraction(numerator - i * denominator, denominator); }


    fraction fraction::operator-=(const fraction& f) {
        numerator = numerator * f.denominator - denominator * f.numerator;
        denominator *= f.denominator;
        return *this;
    }


    fraction operator-(const int i, const fraction& f) {
        return fraction(i * f.denominator - f.numerator, f.denominator);
    }

    fraction fraction::operator/(const fraction& f) const {
        return fraction(numerator * f.denominator, denominator * f.numerator);
    }

    fraction fraction::operator/(const int i) const { return fraction(numerator, denominator * i); }


    fraction fraction::operator/=(const fraction& f) {
        numerator *= f.denominator;
        denominator *= f.numerator;
        return *this;
    }

    void fraction::write_in_file(const std::string& file_name) const {
        std::ofstream file(file_name);

        std::stringstream ss;
        ss << numerator << "/" << denominator;
        file << ss.str();
    }

    fraction fraction::from_file(const std::string& file_name) {
        std::ifstream file(file_name);

        fraction f;
        file >> f;

        return f;
    }


    fraction operator/(const int i, const fraction& f) { return fraction(f.denominator * i, f.numerator); }

    bool operator<(const fraction& lhs, const fraction& rhs) {
        if (lhs.numerator < rhs.numerator)
            return true;
        if (rhs.numerator < lhs.numerator)
            return false;
        return lhs.denominator < rhs.denominator;
    }

    bool operator<=(const fraction& lhs, const fraction& rhs) {
        return rhs >= lhs;
    }

    bool operator>(const fraction& lhs, const fraction& rhs) {
        return rhs < lhs;
    }

    bool operator>=(const fraction& lhs, const fraction& rhs) {
        return !(lhs < rhs);
    }

    std::ostream& operator<<(std::ostream& out, const fraction& f) {
        out << f.numerator << "/" << f.denominator;
        return out;
    }

    std::istream& operator>>(std::istream& in, fraction& f) {
        if (char c; !(in >> f.numerator >> c >> f.denominator) || c != '/') {
            in.setstate(std::ios::failbit);
        }

        if (f.denominator == 0) {
            throw std::logic_error("Error divide by zero");
        }
        return in;
    }
}
