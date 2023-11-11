#pragma once
#include <string>
#include <filesystem>
#include "../system/debug_log.hpp"

#define LOG_TEXTURE

namespace SDLGame {
    class Texture {
        int             sourceWidth;
        int             sourceHeight;

    public:

        Texture(SDL_Renderer* renderer, const std::filesystem::path& imagePath);

        SDL_Rect        sourceRect;
        SDL_Texture*    sdlTexture;
    };
};

