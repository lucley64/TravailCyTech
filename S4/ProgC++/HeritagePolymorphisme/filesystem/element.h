//
// Created by cytech on 06/03/24.
//

#ifndef ELEMENT_H
#define ELEMENT_H
#include <ostream>
#include <string>
#include <utility>


namespace my {
    class element {
    protected:
        std::string name;

    public:
        virtual std::ostream& print(std::ostream& os) const { return os << "name: " << name; }

        friend std::ostream& operator<<(std::ostream& os, const element& obj) {
            return obj.print(os);
        }

        [[nodiscard]] std::string get_name() const;

        void set_name(const std::string& name);

    protected:
        explicit element(std::string  name): name(std::move(name)) {
        }
    public:

        virtual ~element() = default;

        [[nodiscard]] virtual size_t get_size() const = 0;

        [[nodiscard]] virtual double get_compression_rate() const = 0;
    };

    inline std::string element::get_name() const {
        return name;
    }

    inline void element::set_name(const std::string& name) {
        this->name = name;
    }
}


#endif //ELEMENT_H
