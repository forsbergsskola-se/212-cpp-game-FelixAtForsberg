#pragma once
#include <string>
#include <filesystem>
#include "../system/debug_log.h"

namespace fs = std::filesystem;

class Texture {
//    Texture(SDL_Renderer *renderer, std::string &imagePath);

//    SDL_Surface*     CreateSurface(std::string& imagePath );
//    SDL_Texture*     CreateTexture(std::string& imagePath);

    SDL_Renderer*    sdlRenderer;
//    SDL_PixelFormat* sdlFormat;

public:
//    Texture(SDL_Renderer* renderer, SDL_PixelFormat* format, std::string& imagePath);
    Texture(SDL_Renderer* renderer, std::string& imagePath);

    SDL_Texture*     sdlTexture;
};
