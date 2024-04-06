//
// Created by cytech on 19/03/24.
//

#include "robot.h"

#include <utility>
#include <fstream>

namespace my {
    robot::robot(): price() {
    }

    robot::robot(std::string name, std::string type, const double price): name(std::move(name)), type(std::move(type)),
                                                                          price(price) {
    }

    void robot::save_in_file(const std::string& filename) const {
        std::ofstream file(filename, std::ios_base::app);

        file << *this << std::endl;
    }
    std::string robot::get_name() const {
        return name;
    }

    std::string robot::get_type() const {
        return type;
    }

    double robot::get_price() const {
        return price;
    }

    robot& robot::operator=(const robot& r) = default;

    std::vector<robot> robot::robots_from_file(const std::string& filename) {
        std::vector<robot> robots;

        std::ifstream file(filename);

        robot r;
        file >> r;
        while (!file.eof()) {
            robots.push_back(r);
            file >> r;
        }

        return robots;
    }

    std::ostream& operator<<(std::ostream& out, const robot& r) {
        out << r.name << ' ' << r.type << ' ' << r.price;

        return out;
    }

    std::istream& operator>>(std::istream& in, robot& r) {
        // char c1, c2;

        in >> r.name >> r.type >> r.price;

        // if (c1 != ' ' || c2 != ' ') {
        //     in.setstate(std::ios::failbit);
        // }

        return in;
    }
}
