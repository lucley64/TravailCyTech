//
// Created by cytech on 09/02/24.
//
#include "pair.h"

pair::pair(int& a,int &b) : pa(&a), pb(&b) {}

pair::pair(const pair& other) = default;

int pair::getA() const {
    return *pa;
}

int pair::getB() const {
    return *pb;
}



std::ostream& operator << (std::ostream& out, const pair& p) {
    out << "pair: (" << p.getA() << ", " << p.getB() << ") ";
    return out;
}

