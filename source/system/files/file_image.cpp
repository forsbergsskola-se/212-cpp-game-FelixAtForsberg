#include "file.h"
#include "file_image.h"
#include <span>
#include <iostream>
#include <bit>

using SDLGame::System::IMAGE_TYPE,
        SDLGame::System::Image,
        std::string,
        std::array;

// make clang-tidy not complain about "always true" for endian check
#pragma clang diagnostic push
#pragma ide diagnostic ignored "ConstantConditionsOC"

SDLGame::System::Image::Image(string &imagePath) : SDLGame::System::File(imagePath) {

    array<unsigned char, 8> sigBuffer = {NULL};
    fileStream.read(reinterpret_cast<char *>(sigBuffer.data()), sigBuffer.size());

    if (sigBuffer == PNG_SIGNATURE) {
        imageType = IMAGE_TYPE::PNG;

#ifdef LOG_FILE_IMAGE_CTOR
        std::cout << "IMAGE TYPE: PNG" << std::endl;
#endif

        bool wrongEndian;

        // we portable af
        if constexpr (std::endian::native == std::endian::little) {
            wrongEndian = true;
        }


        // wasting 4 bytes here to avoid repetition, hopefully the compiler will get it.
        array<unsigned char, 4> widthBytes{NULL};
        array<unsigned char, 4> heightBytes{NULL};

        fileStream.seekg(PNG_OFFSET_WIDTH, std::ios::beg); // Width is stored at offset 18
        fileStream.read(reinterpret_cast<char *>(&widthBytes), 4);


        // store our read bytes if we need to swap bytes for endian
        fileStream.seekg(PNG_OFFSET_HEIGHT, std::ios::beg); // Height is stored at offset 22
        fileStream.read(reinterpret_cast<char *>(&heightBytes), 4);

        if (wrongEndian) {
            ConvertEndian(widthBytes);
            width = *reinterpret_cast<int *>(widthBytes.data());
            ConvertEndian(heightBytes);
            height = *reinterpret_cast<int *>(heightBytes.data());
        }
#ifdef LOG_FILE_IMAGE_CTOR
        std::cout << std::dec << "width, height: " << width << " , " << height << " " << std::endl;
#endif

        rect = SDL_Rect {0,0, width, height};
    }

}

#pragma clang diagnostic pop