//
// Created by cytech on 06/03/24.
//

#ifndef ENCODING_H
#define ENCODING_H
#include <ostream>


namespace my {
    class encoding {
        int v;

        [[nodiscard]] std::string get_name() const {
            switch (v) {
                case ACSII:
                    return "ACSII";
                case UNICODE:
                    return "Unicode";
                default:
                    return "";
            }
        }
    public:
        enum value: int {
            ACSII,
            UNICODE
        };

        constexpr explicit encoding(const value v): v(v) {
        }

        friend bool operator==(const encoding& lhs, const encoding& rhs) {
            return lhs.v == rhs.v;
        }

        friend bool operator!=(const encoding& lhs, const encoding& rhs) {
            return !(lhs == rhs);
        }


        friend std::ostream& operator<<(std::ostream& os, const encoding& obj) {
            return os << "name: " << obj.get_name();
        }

    };
}


#endif //ENCODING_H
