//
// Created by cytech on 06/03/24.
//

#include "electric.h"

namespace my {
    electric::electric(const double voltage, const double amperage) : voltage(voltage), amperage(amperage){
    }


    double electric::get_voltage() const {
        return voltage;
    }

    void electric::set_voltage(double voltage) {
        this->voltage = voltage;
    }

    double electric::get_amperage() const {
        return amperage;
    }

    void electric::set_amperage(double amperage) {
        this->amperage = amperage;
    }
}
