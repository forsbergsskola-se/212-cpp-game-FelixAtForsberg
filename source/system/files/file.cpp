#include "file.h"
#include <fstream>
#include <iostream>

using namespace SDLGame::System;


namespace fs = std::filesystem;

using std::string, std::ifstream;

File::File(string &fromPath)
    : fileStream(fromPath, std::ios::binary),
      exists(fileStream.good()) {
}