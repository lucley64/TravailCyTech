//
// Created by cytech on 09/02/24.
//

#ifndef GARLAND_H
#define GARLAND_H
#include <vector>


#include "light.h"

namespace my {
    /**
     * \brief Represents a garland wich contains multiple lights
     */
    class garland final : public electric {
        /**
        * \brief The size of the garland
        */
        size_t nb_lights;
        /**
         * \brief The lights within the garland
         */
        mutable std::vector<light> lights;

        double margin = 1.1;

    public:
        /**
         * \brief Constructs a new garland of size n
         * \param n Number of lights
         */
        explicit garland(size_t n = 0);

        explicit garland(const std::vector<light>& lights);

        /**
         * \brief Destructor
         */
        ~garland() override;

        garland operator+(const garland& g) const;

        garland operator+=(const garland& g);

        garland operator+(int i) const;

        friend garland operator+(int i, const garland& g);

        // garland operator*(const garland& g);
        garland operator*=(int n);

        garland operator*(int n) const;

        friend garland operator*(int n, const garland& g);

        garland operator-(const garland& g) const;

        // garland operator-=(const garland &g);
        // garland operator-(int n) const;
        // friend garland operator-(int n, const garland &g);

        // garland operator/(const garland &g) const;
        // garland operator/=(const garland &g);
        garland operator/(int n) const;

        // friend garland operator/(int n, const garland &g);


        const light& operator[](size_t n) const;

        [[nodiscard]] size_t get_nb_lights() const;

        /**
         * \brief Toggles the lights of the garland
         */
        void toggle();

        friend std::ostream& operator<<(std::ostream& out, const garland& g);

        friend std::istream& operator>>(std::istream& in, garland& g);

        garland operator<<(const light& l);

        void turn_on();

        void turn_off();

        void force_turn_on();

        double get_power() const override;

        static garland from_file(const std::string& filename);

        void save_to_file(const std::string& filename) const;

        double get_production_cost() const;

        double minimum_selling_cost() const;

        [[nodiscard]] double margin1() const;

        void set_margin(double margin);
    };
}


#endif // GARLAND_H
