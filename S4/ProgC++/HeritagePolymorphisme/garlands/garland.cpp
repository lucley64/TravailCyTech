//
// Created by cytech on 09/02/24.
//

#include "garland.h"

#include <algorithm>

garland::garland(const size_t n) : nb_lights(n), lights(n) {
    set_amperage(0);
}

garland::garland(const std::vector<light>& lights) : nb_lights(lights.capacity()), lights(lights) {
    double sum_amperage = 0.0;
    for (const auto& l: this->lights) {
        sum_amperage += l.is_on() ? l.get_amperage() : 0;
    }
    set_amperage(sum_amperage);
}

garland::~garland() = default;


size_t garland::get_nb_lights() const { return nb_lights; }

const light& garland::operator[](const size_t n) const { return lights[n]; }


std::ostream& operator<<(std::ostream& out, const garland& g) {
    for (size_t i = 0; i < g.get_nb_lights(); i++) {
        out << g[i];
    }
    return out;
}

void garland::toggle() {
    std::for_each(lights.begin(), lights.end(), [](light& l) { l.toggle(); });
    double sum_amperage = 0.0;
    for (const auto& l: this->lights) {
        sum_amperage += l.is_on() ? l.get_amperage() : 0;
    }
    set_amperage(sum_amperage);
}

garland garland::operator+(const garland& g) const {
    std::vector<light> new_lights;

    new_lights.reserve(nb_lights + g.nb_lights);
    for (const auto& l: lights) {
        new_lights.emplace_back(l);
    }
    for (const auto& l: g.lights) {
        new_lights.emplace_back(l);
    }

    return garland(new_lights);
}

garland garland::operator+(const int n) const {
    std::vector<light> new_lights;
    new_lights.reserve(nb_lights + n);

    for (const auto& l: lights) {
        new_lights.emplace_back(l);
    }

    return garland(new_lights);
}

garland garland::operator+=(const garland& g) {
    std::vector<light> new_lights;

    new_lights.reserve(nb_lights + g.nb_lights);

    for (const auto& l: lights) {
        new_lights.emplace_back(l);
    }
    for (const auto& l: g.lights) {
        new_lights.emplace_back(l);
    }

    lights = new_lights;
    nb_lights = lights.capacity();

    return *this;
}

garland operator+(const int i, const garland& g) { return g + i; }

garland garland::operator*(const int n) const {
    std::vector<light> new_lights;

    new_lights.reserve(nb_lights * n);

    for (size_t i = 0; i < new_lights.capacity(); i++) {
        new_lights.emplace_back(lights[i - nb_lights * (i / nb_lights)]);
    }

    return garland(new_lights);
}

garland garland::operator*=(const int n) {
    std::vector<light> new_lights;

    new_lights.reserve(nb_lights * n);

    for (size_t i = 0; i < new_lights.capacity(); i++) {
        new_lights.emplace_back(lights[i - nb_lights * (i / nb_lights)]);
    }
    lights = new_lights;
    nb_lights = new_lights.capacity();
    return *this;
}

garland operator*(const int n, const garland& g) { return g * n; }

garland garland::operator/(const int n) const {
    std::vector<light> new_lights;

    new_lights.reserve(nb_lights / n);

    for (size_t i = 0; i < new_lights.capacity(); i++) {
        new_lights.emplace_back(lights[i * n].is_on(), lights[i * n].is_on(), lights[i * n].get_voltage(), lights[i  * n].get_amperage());
    }

    return garland(new_lights);
}

garland garland::operator-(const garland& g) const {
    if (nb_lights >= g.get_nb_lights()) {
        bool matched = true;
        for (size_t i = 0; i < g.nb_lights && matched; ++i) {
            matched = lights[nb_lights - 1 - i] == g[g.nb_lights - 1 - i];
        }

        if (matched) {
            std::vector<light> new_lights;

            new_lights.reserve(nb_lights - g.get_nb_lights());

            for (size_t i = 0; i < new_lights.capacity(); ++i) {
                new_lights.emplace_back(lights[i]);
            }

            return garland(new_lights);
        }
    }
    return *this;
}

void garland::turn_on() {
    double sum_amperage = 0.0;
    for (auto& l: this->lights) {
        if (!l.is_on()) {
            l.toggle();
        }
        sum_amperage += l.is_on() ? l.get_amperage() : 0;
    }
    set_amperage(sum_amperage);
}

void garland::turn_off() {
    double sum_amperage = 0.0;
    for (auto& l: this->lights) {
        if (l.is_on()) {
            l.toggle();
        }
        sum_amperage += l.is_on() ? l.get_amperage() : 0;
    }
    set_amperage(sum_amperage);
}

double garland::get_power() const {
    double sum_amperage = 0;
    for (const auto& l: lights) {
        sum_amperage += l.is_on() ? l.get_amperage() : 0;
    }
    return sum_amperage * get_voltage();
}

void garland::force_turn_on() {
    double sum_amperage = 0.0;
    for (auto& l: this->lights) {
        if (!l.is_on()) {
            l.force_turn_on();
        }
        sum_amperage += l.is_on() ? l.get_amperage() : 0;
    }
    set_amperage(sum_amperage);
}

