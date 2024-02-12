#ifndef LIGHT_H
#define LIGHT_H

#include <ostream>

/**
 * \brief Represents a light wich can be on or off
 */
class light {
    /**
     * \brief State of the light
     */
    bool on;

public:
    /**
     * \brief Default light is off.
     */
    light();

    /**
     * \brief Default destructor.
     */
    ~light();

    /**
     * \brief Toggle the light off->on or on->off.
     */
    void toggle();

    /**
     * \brief Returns if the light is on.
     * \return If the light is on true else false
     */
    [[nodiscard]] bool isOn() const;

    friend std::ostream& operator <<(std::ostream& out, const light& l);
};


#endif //LIGHT_H
