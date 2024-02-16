//
// Created by cytech on 16/02/24.
//

#include "time.h"

namespace my {
    time::time(const uint16_t hour, const uint16_t minute, const uint16_t second) :
    hour(hour), minute(minute), second(second) {}

    bool operator==(const time &lhs, const time &rhs) {
        return lhs.hour == rhs.hour && lhs.minute == rhs.minute && lhs.second == rhs.second;
    }

    bool operator!=(const time &lhs, const time &rhs) { return !(lhs == rhs); }

    bool operator<(const time &lhs, const time &rhs) {
        if (lhs.hour < rhs.hour)
            return true;
        if (rhs.hour < lhs.hour)
            return false;
        if (lhs.minute < rhs.minute)
            return true;
        if (rhs.minute < lhs.minute)
            return false;
        return lhs.second < rhs.second;
    }
    bool operator<=(const time &lhs, const time &rhs) { return rhs >= lhs; }
    bool operator>(const time &lhs, const time &rhs) { return rhs < lhs; }
    bool operator>=(const time &lhs, const time &rhs) { return !(lhs < rhs); }

    time operator++(time &t) {
        if (t.second < 59) {
            t.second++;
        } else if (t.minute < 59) {
            t.second = 0;
            t.minute++;
        } else if (t.hour < 23) {
            t.second = 0;
            t.minute = 0;
            t.hour++;
        } else {
            t.second = 0;
            t.minute = 0;
            t.hour = 0;
        }
        return t;
    }



    std::ostream &operator<<(std::ostream &os, const time &obj) {
        return os << "hour: " << obj.hour << " minute: " << obj.minute << " second: " << obj.second;
    }
}