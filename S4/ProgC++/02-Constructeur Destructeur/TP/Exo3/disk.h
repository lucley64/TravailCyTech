//
// Created by cytech on 09/02/24.
//

#ifndef DISK_H
#define DISK_H
#include <ostream>


class disk {
    int diameter;
public:
    disk(int diameter);
    ~disk() = default;

    [[nodiscard]] int get_diameter() const;

    friend std::ostream& operator<<(std::ostream& out, const disk& d);
};



#endif //DISK_H
