//
// Created by cytech on 05/03/24.
//

#include "person.h"

#include <iostream>
#include <utility>

person::person(std::string name) : name(std::move(name)) {
}


std::string person::get_name() const {
    return name;
}

void person::print() const {
    std::cout << "Personne: " << name << "." << std::endl;
}
