#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <string>
#include <filesystem>

#include "texture.h"
#include "../system/files/file.h"
#include "../system/files/file_image.h"
#include "../system/system_static.h"

using namespace SDLGame;
using SDLGame::Texture,
      System::File,
      System::Image,
      std::string;

Texture::Texture(SDL_Renderer* renderer, const std::filesystem::path& imagePath)  {

    const std::filesystem::path usableRelImagePath = System::AsRelAssetPath(imagePath);

    const Image imgFile(usableRelImagePath);

    if (!imgFile.exists) {
        DebugLog::LogError("Attempted to create texture with non-existent path: ", imagePath);
    }

    this->sourceWidth  = imgFile.width;
    this->sourceHeight = imgFile.height;

//    SDL_Rect rect = {0, 0, imgFile.width, imgFile.height};
    this->sourceRect = SDL_Rect {0,0,sourceWidth, sourceHeight};

#ifdef LOG_TEXTURE
    DebugLog::Log("Texture Constructor called.",
                  "\n imagePath:       ", imagePath,
                  "\n usableImagePath: ", usableRelImagePath,
                  "\n sourceWidth, sourceHeight: ", sourceWidth, ",", sourceHeight,
                  "\n sourceRect: "
                  "(",sourceRect.w,",",sourceRect.h,",",sourceRect.x,",", sourceRect.y,")");
#endif

    sdlTexture = IMG_LoadTexture(renderer, System::AsRelAssetPath(imagePath).c_str());


    if (sdlTexture == nullptr) {
        DebugLog::LogWithSDLError(std::string("Unable to load image:"), imagePath);
    }
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
//    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, imgSurface);
//    return newTexture;
//}


