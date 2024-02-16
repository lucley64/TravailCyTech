//
// Created by cytech on 16/02/24.
//

#ifndef TIME_H
#define TIME_H
#include <cstdint>
#include <ostream>


namespace my {
    class time {
        uint16_t hour;
        uint16_t minute;
        uint16_t second;

    public:
        time(uint16_t hour, uint16_t minute, uint16_t second);

        friend bool operator==(const time &lhs, const time &rhs);
        friend bool operator!=(const time &lhs, const time &rhs);

        friend bool operator<(const time &lhs, const time &rhs);
        friend bool operator<=(const time &lhs, const time &rhs);
        friend bool operator>(const time &lhs, const time &rhs);
        friend bool operator>=(const time &lhs, const time &rhs);

        friend time operator++(time& t);
        time operator++();
        friend time operator--(time &t);
        time operator--();

        friend std::ostream &operator<<(std::ostream &os, const time &obj);
    };
}



#endif //TIME_H
