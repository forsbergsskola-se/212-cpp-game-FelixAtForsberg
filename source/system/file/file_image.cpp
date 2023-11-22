#include "file.h"
#include "file_image.h"
#include "../../system/debug_log.hpp"
#include <span>
#include <iostream>
#include <bit>

using SDLGame::System::IMAGE_TYPE,
        SDLGame::System::Image,
        std::string,
        std::array,
        std::filesystem::path;

// make clang-tidy not complain about "always true" for endian check
#pragma clang diagnostic push
#pragma ide diagnostic ignored "ConstantConditionsOC"

Image::Image(const path& imagePath) : File(imagePath) {

    array<unsigned char, 8> sigBuffer = {};
    fileStream.read(reinterpret_cast<char *>(sigBuffer.data()), sigBuffer.size());

    std::cout << "Image Constructor" << std::endl;

    if (sigBuffer == PNG_SIGNATURE) {
        type = IMAGE_TYPE::PNG;

#ifdef LOG_FILE_IMAGE_CTOR
         DebugLog::LogSuccess("PNG identified by signature");
#endif
        // wasting 4 bytes here to avoid repetition, perhaps compiler optimizations will catch it.
        array<unsigned char, 4> widthBytes{};
        array<unsigned char, 4> heightBytes{};

        fileStream.seekg(PNG_OFFSET_WIDTH, std::ios::beg); // Width is stored at offset 18
        fileStream.read(reinterpret_cast<char *>(&widthBytes), 4);

        // store our read bytes if we need to swap bytes for endian
        fileStream.seekg(PNG_OFFSET_HEIGHT, std::ios::beg); // Height is stored at offset 22
        fileStream.read(reinterpret_cast<char *>(&heightBytes), 4);

        // we portable af - swap endian of numbers if we're on little endian, so they read properly
        if constexpr(std::endian::native == std::endian::little) {
            ConvertEndian(widthBytes);
            width = *reinterpret_cast<int *>(widthBytes.data());
            ConvertEndian(heightBytes);
            height = *reinterpret_cast<int *>(heightBytes.data());
        }

#ifdef LOG_FILE_IMAGE_CTOR
        std::cout << std::dec << "width, height: " << width << "," << height << std::endl;
#endif
    } else {
        type = IMAGE_TYPE::INVALID;
        #ifdef LOG_FILE_IMAGE_CTOR
        std::cout << "No known image signature found. "
                     "Image type = invalid." << std::endl;
        #endif
    }




}

#pragma clang diagnostic pop