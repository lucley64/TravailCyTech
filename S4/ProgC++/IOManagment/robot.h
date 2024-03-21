//
// Created by cytech on 19/03/24.
//

#ifndef ROBOT_H
#define ROBOT_H
#include <string>
#include <vector>


namespace my {
    class robot {
        std::string name;
        std::string type;
        double price;

        robot();

    public:
        robot(std::string name, std::string type, double price);


        void save_in_file(const std::string& filename) const;

        [[nodiscard]] std::string get_name() const;

        [[nodiscard]] std::string get_type() const;

        [[nodiscard]] double get_price() const;

        robot& operator=(const robot& r);

        friend std::ostream& operator<<(std::ostream& out, const robot& r);

        friend std::istream& operator>>(std::istream& in, robot& r);

        static std::vector<robot> robots_from_file(const std::string& filename);
    };
}


#endif //ROBOT_H
