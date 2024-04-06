//
// Created by cytech on 05/03/24.
//

#ifndef PERSONNE_H
#define PERSONNE_H
#include <string>


class person {
    std::string name;

public:
    explicit person(std::string name);

    [[nodiscard]] std::string get_name() const;

    void print() const;
};


#endif //PERSONNE_H
