#include "vector.h"

#include <cstdlib>
#include <stdexcept>


my::vector::vector(const size_t size): size(size) {
    elements = static_cast<int *>(malloc(size));
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


