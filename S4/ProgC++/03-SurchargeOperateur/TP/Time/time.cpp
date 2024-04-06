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

    std::ostream &operator<<(std::ostream &os, const time &obj) {
        return os << "hour: " << obj.hour << " minute: " << obj.minute << " second: " << obj.second;
    }

    time time::operator++(int n) {
        if (this->second < 59) {
            this->second++;
        } else if (this->minute < 59) {
            this->second = 0;
            this->minute++;
        } else if (this->hour < 23) {
            this->second = 0;
            this->minute = 0;
            this->hour++;
        } else {
            this->second = 0;
            this->minute = 0;
            this->hour = 0;
        }
        return *this;
    }

    time time::operator--(int n) {
        if (this->second > 0) {
            this->second--;
        } else if (this->minute > 0) {
            this->second = 59;
            this->minute--;
        } else if (this->hour > 0) {
            this->second = 59;
            this->minute = 59;
            this->hour--;
        } else {
            this->second = 59;
            this->minute = 59;
            this->hour = 23;
        }
        return *this;
    }


}