#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <string>

#include "texture.h"
#include "../system/files/file.h"
#include "../system/files/file_image.h"

using namespace SDLGame;
using SDLGame::Texture,
      System::File,
      System::Image,
      std::string;

Texture::Texture(SDL_Renderer* renderer, std::string& imagePath)  {

    const Image imgFile(imagePath);

    if (!imgFile.exists) {
        // Make string because one template argument cannot be 2 different types
        DebugLog::LogError("Attempted to create texture with non-existent path: ", imagePath);
    }
    sdlTexture = IMG_LoadTexture(renderer, imagePath.c_str());

    if (sdlTexture == nullptr) {
        DebugLog::LogWithSDLError(std::string("Unable to load image:"), imagePath);
    }

    sourceWidth = imgFile.width;
    sourceHeight = imgFile.height;

    nativeRect = {0, 0,  sourceWidth, sourceHeight};
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


