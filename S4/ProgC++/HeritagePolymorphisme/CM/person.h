//
// Created by cytech on 05/03/24.
//

#ifndef PERSONNE_H
#define PERSONNE_H
#include <string>


class person {
    std::string name;
    std::string first_name;

public:
    [[nodiscard]] std::string get_first_name() const;

    void set_first_name(const std::string& first_name);

    explicit person(std::string name, std::string  first_name);

    [[nodiscard]] std::string get_name() const;
    void set_name(const std::string& name);

    virtual void print() const;

    virtual ~person() = default;
};


#endif //PERSONNE_H
