#include <SDL_image.h>
#include <string>
#include "texture_factory.h"
#include "../system/debug_prints.h"

SDL_Renderer* TextureFactory::renderer = nullptr;
SDL_PixelFormat* TextureFactory::format = nullptr;

SDL_Surface* TextureFactory::CreateSurface(std::string &imagePath) {
    assert(renderer != nullptr);
    assert(format != nullptr);

    SDL_Surface* newSurface;

    if (!(newSurface = IMG_Load(imagePath.c_str()))) {
        DebugLog::LogFailure(std::string("Unable to load image:"), imagePath);
        std::exit(1);
    }

    SDL_Surface* optimizedSurface = SDL_ConvertSurface(newSurface, format, 0 );
    if( optimizedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", imagePath.c_str(), IMG_GetError() );
        return newSurface;
    }
    SDL_FreeSurface(newSurface);
    return optimizedSurface;
}


// TODO 2 Introduce your own Texture Class to hold the Texture
// Constructor: (Assign <- or Load Texture) Destructor: Free the Texture
// When you do that, you'll probably get some exceptions in your Render Loop
// Put some Logs in your Destructor to see that it actually gets invoked when you don't want it to
// When you notice that, you'll have to look at:
// Copy-Constructor & Move-Constructor.
// Tip: Delete the Copy-Constructor

SDL_Texture* TextureFactory::CreateTexture(std::string &imagePath) {

    SDL_Surface* imgSurface = TextureFactory::CreateSurface(imagePath);
    // TODO 1: Create Texture from Surface
    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, imgSurface);
    return newTexture;
}

