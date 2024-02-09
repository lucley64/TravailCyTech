#include "vector.h"

#include <cstdlib>
#include <stdexcept>


my::vector::vector(const size_t size): size(size) {
    elements = new int[size];
    for (size_t i = 0; i < size; ++i) {
        elements[i] = 0;
    }
}

my::vector::vector(const vector& v): size(v.get_size()), elements(new int[v.get_size()]) {
    for (size_t i = 0; i < v.get_size(); i++) {
        elements[i] = v[i];
    }
}


size_t my::vector::get_size() const {
    return size;
}

int& my::vector::operator[](const unsigned long i) const {
    if (i < size) {
        return elements[i];
    }
    throw std::out_of_range("Index " + std::to_string(i) + " is out of range.");
}


