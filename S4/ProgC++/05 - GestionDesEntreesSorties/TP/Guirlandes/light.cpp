#include "light.h"

namespace my {
    void light::toggle() {
        on = can_on && !on;
    }

    bool light::is_on() const { return on; }

    bool light::can_be_on() const { return can_on; }

    double light::get_buying_cost() const {
        return buying_cost;
    }

    light::light(const double voltage, const double amperage): electric(voltage, amperage), on(false),
                                                               buying_cost((voltage * amperage) * factor) {
    }

    light::~light() = default;

    std::ostream& operator <<(std::ostream& out, const light& l) {
        out << (l.is_on() ? l.get_amperage() < .1 ? "o" : "O" : ".");
        return out;
    }

    light::light(const light& l): electric(l), on(l.is_on()), can_on(l.can_on),
                                  buying_cost((l.get_voltage() * l.get_amperage()) * factor) {
    }

    light::light(const bool can_on, const double voltage, const double amperage): electric(voltage, amperage),
        on(false),
        can_on(can_on), buying_cost((voltage * amperage) * factor) {
    }

    light::light(const bool on, const bool can_on, const double voltage,
                 const double amperage): electric(voltage, amperage), on(on), can_on(can_on), buying_cost((voltage * amperage) * factor) {
    }


    bool light::operator==(const light& l) const { return on == l.on && can_on == l.can_on; }

    double light::get_power() const {
        return is_on() ? get_amperage() * get_voltage() : 0;
    }

    void light::force_turn_on() {
        can_on = true;
        on = true;
    }
}
