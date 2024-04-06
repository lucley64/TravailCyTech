//
// Created by cytech on 07/02/24.
//

#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>


namespace my {
    class fraction {
        int numerator;
        int denominator;

        void simplify();

    public:
        explicit fraction(int n = 0, int d = 1);

        explicit fraction(double d);

        fraction(const fraction& f);

        ~fraction() = default;

        [[nodiscard]] double decimal() const;

        fraction& operator=(const fraction& f);

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

        friend bool operator<(const fraction& lhs, const fraction& rhs);

        friend bool operator<=(const fraction& lhs, const fraction& rhs);

        friend bool operator>(const fraction& lhs, const fraction& rhs);

        friend bool operator>=(const fraction& lhs, const fraction& rhs);

        friend std::ostream& operator <<(std::ostream& out, const fraction& f);

        friend std::istream& operator >>(std::istream& in, fraction& f);

        void write_in_file(const std::string& file_name) const;

        static fraction from_file(const std::string& file_name);
    };
}


#endif //FRACTION_H
