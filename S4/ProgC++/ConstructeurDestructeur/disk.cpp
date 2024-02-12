//
// Created by cytech on 09/02/24.
//

#include "disk.h"

disk::disk(const int diameter) : diameter(diameter){}

int disk::get_diameter() const {
    return diameter;
}

std::ostream& operator<<(std::ostream& out, const disk& d) {
    for (size_t i =0; i < d.get_diameter(); i++) {
        out << "-";
    }
    return out;
}



