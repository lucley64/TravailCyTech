//
// Created by cytech on 09/02/24.
//

#include "garland.h"

#include <algorithm>

garland::garland(const size_t n) : nb_lights(n), lights(n) {}

garland::garland(const std::vector<light> &lights) : nb_lights(lights.capacity()), lights(lights) {}

garland::~garland() = default;


size_t garland::get_nb_lights() const { return nb_lights; }

const light &garland::operator[](const size_t n) const { return lights[n]; }


std::ostream &operator<<(std::ostream &out, const garland &g) {
    for (size_t i = 0; i < g.get_nb_lights(); i++) {
        out << g[i];
    }
    return out;
}

void garland::toggle() const {
    std::for_each(lights.begin(), lights.end(), [](light &l) { l.toggle(); });
}

garland garland::operator+(const garland &g) const {
    std::vector<light> new_lights;

    new_lights.reserve(nb_lights + g.nb_lights);
    for (const auto &l: lights) {
        new_lights.emplace_back(l);
    }
    for (const auto &l: g.lights) {
        new_lights.emplace_back(l);
    }

    return garland(new_lights);
}

garland garland::operator+(const int n) const {
    std::vector<light> new_lights;
    new_lights.reserve(nb_lights + n);

    for (const auto &l: lights) {
        new_lights.emplace_back(l);
    }

    return garland(new_lights);
}

garland garland::operator+=(const garland &g) {
    std::vector<light> new_lights;

    new_lights.reserve(nb_lights + g.nb_lights);

    for (const auto &l: lights) {
        new_lights.emplace_back(l);
    }
    for (const auto &l: g.lights) {
        new_lights.emplace_back(l);
    }

    lights = new_lights;
    nb_lights = lights.capacity();

    return *this;
}

garland operator+(const int i, const garland &g) { return g + i; }

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

garland operator*(const int n, const garland &g) { return g * n; }

garland garland::operator/(const int n) const {
    std::vector<light> new_lights;

    new_lights.reserve(nb_lights / n);

    for (size_t i = 0; i < new_lights.capacity(); i++) {
        new_lights.emplace_back(lights[i * n].is_on(), lights[i * n].is_on());
    }

    return garland(new_lights);
}

garland garland::operator-(const garland &g) const {
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

void garland::turn_on() const {
    std::for_each(lights.begin(), lights.end(), [](light &l) {
        if (!l.is_on()) {
            l.toggle();
        }
    });
}
void garland::turn_off() const {
    std::for_each(lights.begin(), lights.end(), [](light &l) {
        if (l.is_on()) {
            l.toggle();
        }
    });
}
