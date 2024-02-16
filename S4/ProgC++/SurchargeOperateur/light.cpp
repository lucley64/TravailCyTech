#include "light.h"

void light::toggle() {
    on = can_on && !on;
}

bool light::is_on() const { return on; }
bool light::can_be_on() const {return can_on;}

light::light(): on(false) {
}

light::~light() = default;

std::ostream& operator <<(std::ostream& out, const light& l) {
    out << (l.is_on() ? "O" : ".");
    return out;
}

 light::light(const light &l): on(l.is_on()), can_on(l.can_on) {}

 light::light(const bool can_on): on(false), can_on(can_on) {  }

 light::light(const bool on, const bool can_on): on(on), can_on(can_on) {  }


bool light::operator==(const light &l) const { return on == l.on && can_on == l.can_on; }
