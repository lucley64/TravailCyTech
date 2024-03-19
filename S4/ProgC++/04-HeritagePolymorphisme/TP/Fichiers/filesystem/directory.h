//
// Created by cytech on 06/03/24.
//

#ifndef DIRECTORY_H
#define DIRECTORY_H
#include <ostream>
#include <vector>

#include "element.h"


namespace my {
    class directory final : public element {
        std::vector<element *> elements;
    protected:
        std::ostream& print(std::ostream& os) const override;

    public:
        explicit directory(const std::string& name, const std::vector<element *>& elements = {});

        friend std::ostream& operator<<(std::ostream& os, const directory& obj);

        [[nodiscard]] size_t get_size() const override;

        [[nodiscard]] double get_compression_rate() const override;
    };
}


#endif //DIRECTORY_H
