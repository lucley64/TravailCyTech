#include "light.h"

void light::toggle() {
    on = can_on && !on;
}

bool light::is_on() const { return on; }
bool light::can_be_on() const { return can_on; }

light::light(const double voltage, const double amperage): electric(voltage, amperage), on(false) {
}

light::~light() = default;

std::ostream& operator <<(std::ostream& out, const light& l) {
    out << (l.is_on() ? l.get_amperage() < .1 ? "o" : "O" : ".");
    return out;
}

light::light(const light& l): electric(l), on(l.is_on()), can_on(l.can_on) {
}

light::light(const bool can_on, const double voltage, const double amperage): electric(voltage, amperage), on(false),
                                                                              can_on(can_on) {
}

light::light(const bool on, const bool can_on, const double voltage,
             const double amperage): electric(voltage, amperage), on(on), can_on(can_on) {
}


bool light::operator==(const light& l) const { return on == l.on && can_on == l.can_on; }

double light::get_power() const {
  return is_on() ? get_amperage() * get_voltage() : 0;
}

void light::force_turn_on() {
    can_on = true;
    on = true;
}


