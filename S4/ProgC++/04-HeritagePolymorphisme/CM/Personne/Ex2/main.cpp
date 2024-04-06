#include <iostream>

#include "student.h"

int main() {
    student alain("BERTAILS", "Alain");

    alain.set_id("0001");
    alain.print();

    alain.set_id("0002");
    alain.set_name("TERRIEUR");
    alain.print();

    exit(EXIT_SUCCESS);
}
