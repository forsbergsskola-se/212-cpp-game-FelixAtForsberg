#include <fstream>
#include <iostream>

#include "system/file/file.h"
#include "system/system_static.h"

using namespace SDLGame::System;
namespace fs = std::filesystem;

using std::string, std::ifstream;

File::File(const std::filesystem::path& path)
: path {path},
  fileStream { ifstream{path, std::ios::binary} },
  exists { fileStream.good() } {

}
