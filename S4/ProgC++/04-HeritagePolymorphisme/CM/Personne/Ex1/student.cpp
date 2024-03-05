//
// Created by cytech on 05/03/24.
//

#include "student.h"

#include <iostream>
#include <utility>

student::student(const std::string& name, std::string id): person(name), id(std::move(id)) {
}


std::string student::get_id() const {
    return id;
}


void student::print() const {
    person::print();
    std::cout << "Student: " << id << "." << std::endl;
}
