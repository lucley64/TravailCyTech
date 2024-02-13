//
// Created by cytech on 09/02/24.
//

#include "tower.h"

#include <utility>

tower::tower(std::string name, const std::vector<disk>& disks) : name(std::move(name)), disks(disks) {
}

disk tower::pop_disk() {
    const disk d = disks.at(disks.size() - 1);
    disks.pop_back();
    return d;
}

void tower::push_disk(const disk& d) {
    disks.push_back(d);
}

std::vector<disk> tower::get_disks() const {
    return disks;
}

std::string tower::get_name() const {
    return name;
}


std::ostream& operator<<(std::ostream& out, const tower& t) {
    for (const auto& disk: t.disks) {
        out << disk << std::endl;
    }
    return out;
}

bool tower::operator==(const tower& t) const {
    return name == t.get_name();
}
