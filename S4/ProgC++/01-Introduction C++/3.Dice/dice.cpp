#include <iomanip>
#include <iostream>
#include <random>


constexpr int SIDES = 6;
inline long R_SIDE() { return random() % SIDES + 1; }

int main() {
    constexpr int n_dice = 2;
    srand(clock());

    std::cout << std::endl << "Enter number of trials: ";
    int trials;
    std::cin >> trials;

    int outcomes[n_dice * SIDES] = {0};

    for (int i = 0; i < trials; ++i) {
        outcomes[R_SIDE() + R_SIDE()]++;
    }

    for (int i = 0; i < n_dice * SIDES; ++i) {
        std::cout << "i=" << std::setw(2) << i << " p=" << std::setw(3) << static_cast<double>(
            100 * outcomes[i]) / trials << "%" << std::endl;
    }

    exit(EXIT_SUCCESS);
}
