#pragma once
#include <SDL_surface.h>
#include <SDL_image.h>
#include <string>
#include "../system/error.h"

class TextureFactory {
private:
    static SDL_Surface* CreateSurface(std::string &path );

public:
    static SDL_PixelFormat* Format;
    static SDL_Renderer*    Renderer;
    static SDL_Texture*     CreateTexture(std::string &path);
};


// gpt 3.5-turbo
//+-------------+---------------+----------------+----------------+
//|  Property   |     Image     |    Texture     |    Surface     |
//|-------------|---------------|----------------|----------------|
//|       Usage | General       | Rendering      | Editing        |
//|        Type | Bitmap        | GPU Optimized  | Pixel Buffer   |
//|   Accessing | Direct Access | GPU Access     | Direct Access  |
//|   Modifying | Limited       | Expensive      | Easy           |
//| Performance | Low to Medium | High           | Low to Medium  |
//+-------------+---------------+----------------+----------------+
//|     Memory  | High          | High           | High           |
//|      Saving | A few formats | Not applicable | Many formats   |
//|     Loading | A few formats | Fewer formats  | Many formats   |
//|      Format | Pixel Format  | Pixel Format   | Pixel Format   |
//+-------------+---------------+----------------+----------------+

