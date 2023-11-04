#include <SDL2/SDL.h>
#include <string>
#include <SDL2_image/SDL_image.h>
#include "texture.h"

using namespace SDLGame;

Texture::Texture(SDL_Renderer* renderer, std::string& imagePath)  {

    sdlTexture = IMG_LoadTexture(renderer, imagePath.c_str());

    if (sdlTexture == nullptr) {
        DebugLog::LogWithSDLError(std::string("Unable to load image:"), imagePath);
    }

//    SDL_QueryT
    const SDL_Rect textureRect {0, 0, 100, 100};
//    const SDL_Rect rect {0, 0,  100, 100};
}


// TODO 2 Introduce your own texture Class to hold the texture
// Constructor: (Assign <- or Load texture) Destructor: Free the texture
// When you do that, you'll probably get some exceptions in your Render Loop
// Put some Logs in your Destructor to see that it actually gets invoked when you don't want it to
// When you notice that, you'll have to look at:
// Copy-Constructor & Move-Constructor.
// Tip: Delete the Copy-Constructor

//SDL_Texture* texture::CreateTexture(std::string &imagePath) {

//    SDL_Surface* imgSurface = gtexture::CreateSurface(imagePath);
    // TODO 1: Create texture from Surface
//    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(sdlRenderer, imgSurface);
//    return newTexture;
//}


