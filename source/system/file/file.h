#pragma once

#include <string>
#include <array>
#include <fstream>

namespace SDLGame::System {

//void ConvertEndian(const std::array<T, N>& arr);

    class File {


    public:
        File() = delete;

        std::basic_ifstream<char> fileStream;

        explicit File(const std::filesystem::path& path);

        bool exists;
    };
}
// having to do this song and dance for
// basically somewhat approaching
// declaration separation is quite sad
#include "convert_endian.inl"