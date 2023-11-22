#pragma once
#include <filesystem>

#include "game/game.h"
#include "system/debug_log.hpp"


#define LOG_TEXTURE

namespace SDLGame {
    struct Texture {

        Texture(SDL_Renderer* renderer, const std::filesystem::path& imagePath);

        Dimensions      size;

        SDL_Rect        sdlRect;
        SDL_Texture*    sdlTexture;
    };
};

