#include <iostream>
#include <numeric>
#include <vector>

// Requiers C++23 to compile

constexpr int N = 40;

int main() {
    int accum = 0;
    std::vector<int> data(N);
    std::iota(data.begin(), data.end(), 0);
    accum = std::reduce(data.begin(), data.end());
    std::cout << "The sum is " << accum << std::endl;

    exit(EXIT_SUCCESS);
}
