#include <iostream>

#include "filesystem/directory.h"
#include "filesystem/image.h"
#include "filesystem/text.h"
#include "filesystem/video.h"


int main() {
    const my::directory root("/", {
        new my::directory("home", {
            new my::image("background", "png", 1024, 800, 400),
            new my::video("demo", "mp4", 159327, 3600),
            new my::text("README", "MD", 8052, static_cast<my::encoding>(my::encoding::ACSII)),
        }),
        new my::text("", "config", 512, my::encoding(my::encoding::UNICODE)),
    });

    std::cout << root << std::endl;
    std::cout << "Compression rate: " << root.get_compression_rate() << std::endl;
}
