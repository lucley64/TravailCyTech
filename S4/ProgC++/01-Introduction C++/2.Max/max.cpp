#include <iostream>

#define MAX(a, b) (a < b ? b : a)

int main() {
    int i = MAX(2, 3) + 5;
    std::cout << "i = " << i << std::endl;

    int j = MAX(3, i++) + 5;
    std::cout << "j = " << j << std::endl;
    exit(EXIT_SUCCESS);
}
