//
// Created by cytech on 06/03/24.
//

#ifndef FILE_H
#define FILE_H
#include <ostream>
#include <utility>

#include "element.h"


namespace my {
    class file : public element {
    protected:
        std::string extension;

    public:
        [[nodiscard]] std::string extension1() const;

        void set_extension(const std::string& extension);

        friend std::ostream& operator<<(std::ostream& os, const file& obj);

        std::ostream& print(std::ostream& os) const override;

        [[nodiscard]] size_t size1() const;

        void set_size(size_t size);

    protected:
        size_t size;

    public:
        [[nodiscard]] double get_compression_rate() const override;

    protected:
        file(const std::string& name, std::string extension, const size_t size): element(name),
            extension(std::move(extension)),
            size(size) {
        }
    };

    inline std::ostream& operator<<(std::ostream& os, const file& obj) {
        return obj.print(os);
    }


    inline std::string file::extension1() const {
        return extension;
    }

    inline void file::set_extension(const std::string& extension) {
        this->extension = extension;
    }

    inline std::ostream& file::print(std::ostream& os) const {
        element::print(os);
        return os
               << " extension: " << extension
               << " size: " << size;
    }

    inline size_t file::size1() const {
        return size;
    }

    inline void file::set_size(const size_t size) {
        this->size = size;
    }

    inline double file::get_compression_rate() const {
        return static_cast<double>(get_size()) / static_cast<double>(size);
    }
}


#endif //FILE_H
