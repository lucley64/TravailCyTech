//
// Created by cytech on 09/02/24.
//

#include "garland.h"

garland::garland(const size_t n) : nb_lights(n){
    lights = static_cast<light *>(malloc(sizeof(light) * n));
}

size_t garland::get_nb_lights() const {
    return nb_lights;
}

light& garland::operator[](size_t n) const {
    return lights[n];
}

garland::~garland() {
    free(lights);
}

std::ostream& operator<<(std::ostream& out, const garland& g) {
    for (size_t i = 0; i <g.get_nb_lights(); i++) {
        out << g[i];
    }
    return out;
}

void garland::toggle() const {
    for (size_t i = 0; i <nb_lights; i++) {
        lights[i].toggle();
    }
}



