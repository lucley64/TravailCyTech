//
// Created by cytech on 06/03/24.
//

#include "video.h"

namespace my {
    size_t video::duration1() const {
        return duration;
    }

    void video::set_duration(size_t duration) {
        this->duration = duration;
    }

    video::video(const std::string& name, const std::string& extension, const size_t size, const size_t duration): file(name, extension, size), duration(duration) {
    }

    size_t video::get_size() const {
        return static_cast<size_t>(.8 * static_cast<double>(duration));
    }


    std::ostream& operator<<(std::ostream& os, const video& obj) {
        return obj.print(os);
    }

    std::ostream& video::print(std::ostream& os) const  {
        file::print(os);
        return os
               << " duration: " << duration;
    }
}
