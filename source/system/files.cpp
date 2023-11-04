#include "files.h"
#include <fstream>

using namespace SDLGame;

bool Files::Exist(std::string& imagePath) {
    std::ifstream file(imagePath.c_str());
    return file.good();
}