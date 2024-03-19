#ifndef LIGHT_H
#define LIGHT_H

#include <ostream>

#include "electric.h"

/**
 * \brief Represents a light wich can be on or off
 */
class light final : public electric {
    /**
     * \brief State of the light
     */
    bool on;

    bool can_on = true;

public:
    /**
     * \brief Default light is off.
     */
    explicit light(double voltage = 220, double amperage = .1);

    light(const light& l);

    explicit light(bool can_on, double voltage = 220, double amperage = .1);

    explicit light(bool on, bool can_on, double voltage = 220, double amperage = .1);

    /**
     * \brief Default destructor.
     */
    ~light() override;

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

    bool operator==(const light&) const;

    [[nodiscard]] double get_power() const override;

  void force_turn_on();
};


#endif //LIGHT_H
