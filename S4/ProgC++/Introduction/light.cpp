#include "light.h"

void light::toggle() {
    on = !on;
}

bool light::isOn() const {
    return on;
}

light::light(): on(false) {
}

light::~light() = default;
