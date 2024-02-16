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

    bool can_on = true;

public:
    /**
     * \brief Default light is off.
     */
    light();

    light(const light &l);

    explicit light(bool can_on);

    explicit light(bool on, bool can_on);

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
    [[nodiscard]] bool is_on() const;

    [[nodiscard]] bool can_be_on() const;

    friend std::ostream& operator <<(std::ostream& out, const light& l);

    bool operator==(const light &) const;
};


#endif //LIGHT_H
