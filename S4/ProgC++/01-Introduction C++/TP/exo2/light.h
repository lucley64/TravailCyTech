#ifndef LIGHT_H
#define LIGHT_H


class light {
    bool on;

public:
    light();

    ~light();

    void toggle();

    [[nodiscard]] bool isOn() const;
};


#endif //LIGHT_H
