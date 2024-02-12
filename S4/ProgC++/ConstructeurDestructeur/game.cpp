//
// Created by cytech on 09/02/24.
//

#include "game.h"

#include <cassert>

game::game(const std::vector<tower>& towers) : towers(towers) {assert(towers.size() == 3);}

std::vector<tower> game::get_towers() {
    return towers;
}

tower& game::operator[](const size_t i) {
    return towers.at(i);
}

void move(size_t nb_disk, tower& src, tower& aux, tower& dst);
void move(const size_t nb_disk, tower& src, tower& aux, tower& dst) {
    if (nb_disk == 1) {
        const auto d = src.pop_disk();
        dst.push_disk(d);
        return;
    }
    move(nb_disk - 1, src, dst, aux);
    const auto d = src.pop_disk();
    dst.push_disk(d);
    move(nb_disk - 1, aux, src, dst);
}


void game::solve() {
    move(towers[0].get_disks().size(), towers[0], towers[1], towers[2]);
}

// std::optional<tower> game::operator[](const std::string& name) {
//     if (const auto find = std::find(towers.begin(), towers.end(), [name](const tower& t){return t.get_name() == name;}); find != towers.end()) {
//         return *find;
//     }
//     return {};
// }


std::ostream& operator<<(std::ostream& out, const game& g) {
    for (const auto& tower: g.towers) {
        out << tower << std::endl;
    }
    return out;
}



