#pragma once

#include <string>
#include <array>
#include <fstream>

namespace SDLGame::System {

//void ConvertEndian(const std::array<T, N>& arr);

    class File {
    protected:
        std::basic_ifstream<char> fileStream;

    public:
        File(std::string &fromPath);

        bool exists;
    };
}
// having to do this song and dance for
// basically somewhat approaching
// declaration separation is very sad
#include "convert_endian.inl"