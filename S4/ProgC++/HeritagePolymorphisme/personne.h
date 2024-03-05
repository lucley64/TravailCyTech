//
// Created by cytech on 05/03/24.
//

#ifndef PERSONNE_H
#define PERSONNE_H
#include <string>


class personne {
    std::string name;
public:
    [[nodiscard]] std::string get_name() const;
};



#endif //PERSONNE_H
