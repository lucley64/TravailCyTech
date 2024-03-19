//
// Created by cytech on 06/03/24.
//

#ifndef VIDEO_H
#define VIDEO_H
#include <ostream>

#include "file.h"


namespace my {
    class video final: public file{
        size_t duration;
    public:
        [[nodiscard]] size_t duration1() const;

        friend std::ostream& operator<<(std::ostream& os, const video& obj);

        inline std::ostream& print(std::ostream& os) const override;

        void set_duration(size_t duration);

        video(const std::string& name, const std::string& extension, size_t size, size_t duration);

        [[nodiscard]] size_t get_size() const override;
    };
}



#endif //VIDEO_H
