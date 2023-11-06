#pragma once
#include <string>
#include <array>
#include <fstream>

// https://www.w3.org/TR/PNG-Chunks.html

using std::string;

namespace SDLGame::System {

    class File {
    protected:
        std::basic_ifstream<char> fileStream;

    public:
        File(string& fromPath);


        bool exists;
    };

}
