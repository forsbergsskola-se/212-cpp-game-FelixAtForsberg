#pragma once
#include <string>
#include <filesystem>
#include "../system/debug_log.h"


namespace SDLGame {
    class Texture {
    //    Texture(SDL_Renderer *renderer, std::string &imagePath);

    //    SDL_Surface*     CreateSurface(std::string& imagePath );
    //    SDL_Texture*     CreateTexture(std::string& imagePath);
    //    SDL_PixelFormat* sdlFormat;

        SDL_Renderer*    sdlRenderer;

    public:
        SDL_Texture*     sdlTexture;
        int sourceWidth;
        int sourceHeight;
        SDL_Rect nativeRect;

    //    Texture(SDL_Renderer* renderer, SDL_PixelFormat* format, std::string& imagePath);
        Texture(SDL_Renderer* renderer, std::string& imagePath);

        Texture() = default;
    };
};

