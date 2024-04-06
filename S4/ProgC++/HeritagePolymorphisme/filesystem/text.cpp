//
// Created by cytech on 06/03/24.
//

#include "text.h"

namespace my {
    text::text(const std::string& name, const std::string& extension, const size_t size,
               const encoding file_encoding): file(name, extension, size), file_encoding(file_encoding) {
    }

    size_t text::get_size() const {
        return static_cast<size_t>(static_cast<double>(size) * (file_encoding == static_cast<encoding>(encoding::ACSII) ? .5 : .6));
    }

    encoding text::file_encoding1() const {
        return file_encoding;
    }

    void text::set_file_encoding(encoding file_encoding) {
        this->file_encoding = file_encoding;
    }

    std::ostream& operator<<(std::ostream& os, const text& obj) {
        return obj.print(os);
    }

    std::ostream& text::print(std::ostream& os) const {
        file::print(os);
        return os
               << " file_encoding: " << file_encoding;
    }
}
