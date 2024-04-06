//
// Created by cytech on 05/03/24.
//

#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"


class student : public person {
    std::string id;

public:
    explicit student(const std::string& name, std::string id = "0");

    [[nodiscard]] std::string get_id() const;

    void print() const;
};


#endif //STUDENT_H
