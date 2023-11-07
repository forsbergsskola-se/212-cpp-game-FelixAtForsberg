#pragma once
#include <string>
#include <array>
#include <SDL_rect.h>
#include "file.h"

#define LOG_FILE_IMAGE_CTOR

using std::string;

namespace SDLGame::System {

    constexpr size_t PNG_OFFSET_WIDTH  {0x10};
    constexpr size_t PNG_OFFSET_HEIGHT {0x14};

    // PNG File Signature: 137 80 78 71 13 10 26 10
    constexpr std::array<unsigned char, 8> PNG_SIGNATURE {0x89, 0x50, 0x4E, 0x47, 0xD, 0xA, 0x1A, 0xA};


    enum struct IMAGE_TYPE {
        PNG,
        JPG,
        INVALID
    };

    // http://www.libpng.org/pub/png/spec/1.2/PNG-Structure.html
    // https://www.w3.org/TR/PNG-Chunks.html


        class Image : SDLGame::System::File {

        public:

            Image(string& imagePath);

            IMAGE_TYPE imageType;
            bool exists;
            int height;
            int width;
            SDL_Rect rect;
        };

}