//
// Created by cytech on 05/03/24.
//

#include "student.h"

#include <iostream>
#include <utility>

student::student(const std::string& name, const std::string& first_name, std::string id): person(name, first_name), id(std::move(id)) {
}


std::string student::get_id() const {
    return id;
}

void student::set_id(const std::string& id) {
    this->id = id;
}



void student::print() const {
    person::print();
    std::cout << "Student: " << id << "." << std::endl;
}
