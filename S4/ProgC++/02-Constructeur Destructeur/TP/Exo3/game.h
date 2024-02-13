//
// Created by cytech on 09/02/24.
//

#ifndef GAME_H
#define GAME_H
#include <optional>
#include <vector>

#include "tower.h"


class game {
    std::vector<tower> towers;

public:
    game(const std::vector<tower>& towers);

    ~game() = default;

    void solve();

    std::vector<tower> get_towers();

    tower& operator[](size_t i);

    // std::optional<tower> operator[](const std::string& name);

    friend std::ostream& operator<<(std::ostream& out, const game& g);
};



#endif //GAME_H
