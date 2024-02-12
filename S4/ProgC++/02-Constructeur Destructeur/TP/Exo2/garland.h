//
// Created by cytech on 09/02/24.
//

#ifndef GARLAND_H
#define GARLAND_H
#include "light.h"

/**
 * \brief Represents a garland wich contains multiple lights
 */
class garland {
    /**
     * \brief The size of the garland
     */
    size_t nb_lights;
    /**
     * \brief The lights within the garland
     */
    light* lights;

public:
    /**
     * \brief Constructs a new garland of size n
     * \param n Number of lights
     */
    explicit garland(size_t n);

    /**
     * \brief Destructor
     */
    ~garland();
    light& operator[](size_t n) const;
    [[nodiscard]] size_t get_nb_lights() const;

    /**
     * \brief Toggles the lights of the garland
     */
    void toggle() const;
    friend std::ostream& operator<<(std::ostream& out, const garland& g);
};



#endif //GARLAND_H
