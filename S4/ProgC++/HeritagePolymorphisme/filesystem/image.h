//
// Created by cytech on 06/03/24.
//

#ifndef IMAGE_H
#define IMAGE_H
#include <ostream>

#include "file.h"


namespace my {
    class image final: public file{
        friend std::ostream& operator<<(std::ostream& os, const image& obj);

    public:

        inline std::ostream& print(std::ostream& os) const override;

        [[nodiscard]] size_t width1() const;

        void set_width(size_t width);

        [[nodiscard]] size_t height1() const;

        void set_height(size_t height);

    private:
        size_t width;
        size_t height;

    public:
        image(const std::string& name, const std::string& extension, size_t size, size_t width, size_t height);

        [[nodiscard]] size_t get_size() const override;
    };
}



#endif //IMAGE_H
