#include <iostream>
#include <vector>

#include "light.h"

int main() {
    light ampoule;

    std::cout << "L'ampoule est " << (ampoule.isOn() ? "alumée" : "éteinte") << std::endl;
    ampoule.toggle();
    std::cout << "L'ampoule est " << (ampoule.isOn() ? "alumée" : "éteinte") << std::endl;

    std::vector<light> guirlande(10);

    std::cout << "La guirlande est " << (std::all_of(guirlande.begin(), guirlande.end(),
                                                     [](const light& l) { return l.isOn(); })
                                             ? "alumée"
                                             : "éteinte") << std::endl;
    std::for_each(guirlande.begin(), guirlande.end(), [](light& l) { l.toggle(); });
    std::cout << "La guirlande est " << (std::all_of(guirlande.begin(), guirlande.end(),
                                                     [](const light& l) { return l.isOn(); })
                                             ? "alumée"
                                             : "éteinte") << std::endl;


    exit(EXIT_SUCCESS);
}
