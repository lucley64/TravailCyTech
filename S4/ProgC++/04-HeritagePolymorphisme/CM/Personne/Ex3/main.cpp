#include "student.h"

int main() {
    const student alain("BERTAILS", "Alain", "0001");

    alain.print();

    const person* p = new student("TERRIEUR", "Alain", "0002");
    p->print();

    exit(EXIT_SUCCESS);
}
