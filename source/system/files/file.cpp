#include "file.h"
#include <fstream>

using namespace SDLGame::System;

namespace fs = std::filesystem;

using std::string, std::ifstream;

// file.cpp
File::File(string &fromPath)
    : fileStream(fromPath, std::ios::binary),
      exists(fileStream.good()) {
}
