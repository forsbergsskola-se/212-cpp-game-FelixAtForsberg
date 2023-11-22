#pragma once
#include <string>
#include <filesystem>
#include "../system/debug_log.hpp"
#include "../game/game.h"


#define LOG_TEXTURE

namespace SDLGame {
    struct Texture {

        Texture(SDL_Renderer* renderer, const std::filesystem::path& imagePath);

        Dimensions      size;

        SDL_Rect        sdlRect;
        SDL_Texture*    sdlTexture;
    };
};

