//
// Created by cytech on 06/03/24.
//

#include "directory.h"

namespace my {
    directory::directory(const std::string& name, const std::vector<element *>& elements): element(name),
        elements(elements) {
    }

    size_t directory::get_size() const {
        size_t sum_size = 0;
        for (const auto e: elements) {
            sum_size += e->get_size();
        }
        return sum_size;
    }

    double directory::get_compression_rate() const {
        double sum_rate = 0;
        for (const auto e: elements) {
            sum_rate += e->get_compression_rate();
        }
        return sum_rate;
    }

    std::ostream& operator<<(std::ostream& os, const directory& obj) {
        return obj.print(os);
    }

    std::ostream& directory::print(std::ostream& os) const {
        element::print(os);
        os << " elements: [";
        for (const auto& e: elements) {
            e->print(os);
            os << ", ";
        }
        os << "]";
        return os;
    }
}
