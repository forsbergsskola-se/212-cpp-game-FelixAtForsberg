#pragma once

#include <fstream>

namespace SDLGame::System {

//void ConvertEndian(const std::array<T, N>& arr);

    class File {


    public:

        explicit File(const std::filesystem::path& path);
        File() = delete;

        const std::filesystem::path path;

        // usable as in can be passed to things that expect to find the file
        // meaning: 'resources' directory; relative to executable

        std::ifstream fileStream;

        const bool exists;

        std::filesystem::path usablePath() const;
    };
}
// having to do this song and dance for
// basically somewhat approaching
// declaration separation is wonky
#include "convert_endian.inl"