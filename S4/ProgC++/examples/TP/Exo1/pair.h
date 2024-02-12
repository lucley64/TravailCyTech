// This example is used to illustrate the deep copy principle
#pragma once
#include <iostream>

class pair {
    int* pa;
    int* pb;

public :
    // This constructor should set up pa and pb to point to newly allocated memory locations on the heap
    // and whose values will be a and b, respectively.
    pair(int& a, int& b);

    // This copy constructor should implement a deep copy from the read-only reference "other"
    pair(const pair& other);

    // This destrutor should de-allocate the heap memory properly
    ~pair() = default;

    // An overloaded operator<<, allowing us to print a pair via cout<<
    friend std::ostream& operator<<(std::ostream& out, const pair& p);

    [[nodiscard]] int getA() const;

    [[nodiscard]] int getB() const;
};
