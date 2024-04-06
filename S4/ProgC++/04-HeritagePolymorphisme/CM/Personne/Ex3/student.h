//
// Created by cytech on 05/03/24.
//

#ifndef STUDENT_H
#define STUDENT_H
#include "person.h"


class student : public person {
    std::string id;

public:
    explicit student(const std::string& name, const std::string& first_name, std::string id = "0");

    [[nodiscard]] std::string get_id() const;
    void set_id(const std::string& id);

    void print() const override;

    ~student() override = default;
};


#endif //STUDENT_H
