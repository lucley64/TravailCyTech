//
// Created by cytech on 09/02/24.
//

#ifndef GARLAND_H
#define GARLAND_H
#include <vector>


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
    mutable std::vector<light> lights;

public:
    /**
     * \brief Constructs a new garland of size n
     * \param n Number of lights
     */
    explicit garland(size_t n);

    explicit garland(const std::vector<light> &lights);

    /**
     * \brief Destructor
     */
    ~garland();

    garland operator+(const garland &g) const;
    garland operator+=(const garland &g);
    garland operator+(int i) const;
    friend garland operator+(int i, const garland &g);

    // garland operator*(const garland& g);
    garland operator*=(int n);
    garland operator*(int n) const;
    friend garland operator*(int n, const garland &g);

    garland operator-(const garland &g) const;
    // garland operator-=(const garland &g);
    // garland operator-(int n) const;
    // friend garland operator-(int n, const garland &g);

    // garland operator/(const garland &g) const;
    // garland operator/=(const garland &g);
    garland operator/(int n) const;
    // friend garland operator/(int n, const garland &g);


    const light &operator[](size_t n) const;
    [[nodiscard]] size_t get_nb_lights() const;

    /**
     * \brief Toggles the lights of the garland
     */
    void toggle() const;
    friend std::ostream &operator<<(std::ostream &out, const garland &g);

    void turn_on() const;
    void turn_off() const;
};


#endif // GARLAND_H
