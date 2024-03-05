//
// Created by cytech on 05/03/24.
//

#include "person.h"

#include <iostream>
#include <utility>

std::string person::get_first_name() const {
    return first_name;
}

void person::set_first_name(const std::string& first_name) {
    this->first_name = first_name;
}

person::person(std::string name, std::string first_name) : name(std::move(name)), first_name(std::move(first_name)) {}


std::string person::get_name() const {
    return name;
}

void person::set_name(const std::string& name) {
    this->name = name;
}


void person::print() const {
    std::cout << "Person: " << name << ", " << first_name << "." << std::endl;
}
