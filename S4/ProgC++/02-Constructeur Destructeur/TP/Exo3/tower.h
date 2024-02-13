//
// Created by cytech on 09/02/24.
//

#ifndef TOWER_H
#define TOWER_H
#include <string>
#include <vector>

#include "disk.h"


class tower {
    std::string name;
    std::vector<disk> disks;

public:
    explicit tower(std::string  name, const std::vector<disk>& disks = std::vector<disk>());
    ~tower() = default;

    void push_disk(const disk& d);
    disk pop_disk();

    bool operator==(const tower&) const;

    [[nodiscard]] std::string get_name() const;
    [[nodiscard]] std::vector<disk> get_disks() const;

    friend std::ostream& operator<<(std::ostream& out, const tower& t);
};



#endif //TOWER_H
