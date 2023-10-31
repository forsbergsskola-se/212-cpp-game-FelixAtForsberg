#pragma once
#include <string>

class TextureFactory {
    static SDL_Surface*     CreateSurface(std::string& imagePath );

public:
    static SDL_Renderer*    renderer;
    static SDL_PixelFormat* format;

    static SDL_Texture*     CreateTexture(std::string& imagePath);
};
