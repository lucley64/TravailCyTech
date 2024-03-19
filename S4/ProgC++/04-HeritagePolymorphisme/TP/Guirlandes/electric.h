//
// Created by cytech on 06/03/24.
//

#ifndef ELECTRIC_H
#define ELECTRIC_H


class electric {
    double voltage;
    double amperage;

protected:
    explicit electric(double voltage = 220.0, double amperage = .1);

public:
    virtual ~electric() = default;

    [[nodiscard]] double get_voltage() const;

    void set_voltage(double voltage);

    [[nodiscard]] double get_amperage() const;

    void set_amperage(double amperage);

    [[nodiscard]] virtual double get_power() const = 0;
};


#endif //ELECTRIC_H
