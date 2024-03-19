//
// Created by cytech on 06/03/24.
//

#ifndef TEXT_H
#define TEXT_H
#include <ostream>

#include "encoding.h"
#include "file.h"


namespace my {
    class text final: public file {
        encoding file_encoding;

    public:
        text(const std::string& name, const std::string& extension, size_t size, encoding file_encoding);

        [[nodiscard]] size_t get_size() const override;

        friend std::ostream& operator<<(std::ostream& os, const text& obj);

        inline std::ostream& print(std::ostream& os) const override;

        [[nodiscard]] encoding file_encoding1() const;

        void set_file_encoding(encoding file_encoding);
    };
}



#endif //TEXT_H
