//
// Created by cytech on 06/03/24.
//

#include "image.h"

namespace my {
    std::ostream& image::print(std::ostream& os) const  {
        file::print(os);
        return os
               << " width: " << width
               << " height: " << height;
    }

    size_t image::width1() const {
        return width;
    }

    void image::set_width(size_t width) {
        this->width = width;
    }

    size_t image::height1() const {
        return height;
    }

    void image::set_height(size_t height) {
        this->height = height;
    }

    image::image(const std::string& name, const std::string& extension, const size_t size, const size_t width, const size_t height): file(name, extension, size), width(width), height(height) {
    }

    size_t image::get_size() const {
        return height * width / 2;
    }


    std::ostream& operator<<(std::ostream& os, const image& obj) {
        return obj.print(os);
    }
}
