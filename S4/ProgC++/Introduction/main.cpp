#include <iostream>

template <typename T>
void swap(T &a, T &b) noexcept {
    T temp = a;
    a = b;
    b = temp;
}

int main() {

    int i = 2, j = 3;

    std::cout << "i = " << i << ", j = " << j << std::endl;

    swap(i, j);

    std::cout << "i = " << i << ", j = " << j << std::endl;

    exit(EXIT_SUCCESS);
}
