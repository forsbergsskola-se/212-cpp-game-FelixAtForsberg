#include "graphics/texture.h"

#include <filesystem>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "system/system_static.h"
#include "system/file/file.h"
#include "system/file/file_image.h"

using namespace SDLGame;
using SDLGame::Texture,
        System::File,
        System::Image,
        std::string;

Texture::Texture( const std::filesystem::path& imagePath, const std::weak_ptr<RenderContext>& context ) : renderContext( context ) {
    __STORE_CTOR_LINE__
    const std::filesystem::path usableRelImagePath = System::AsRelAssetPath( imagePath );

    const Image imgFile( usableRelImagePath );

    if(!imgFile.exists) {
        DebugLog::LogError( "Attempted to create texture with non-existent path: ", imagePath );
    }

    this->size = Dimensions{ imgFile.width, imgFile.height };

    //    SDL_Rect rect = {0, 0, imgFile.width, imgFile.height};
    this->sdl.nativeRect = SDL_Rect { 0, 0, imgFile.width, imgFile.height };

#ifdef LOG_TEXTURE
    DebugLog::LogCyan( "Texture Constructor called" );
    DebugLog::Log( " source:          \"", __FILE__, ":", __CTOR_LINE__, "\"",
                   "\n imagePath:       ", imagePath,
                   "\n usableImagePath: ", usableRelImagePath,
                   "\n sourceWidth, sourceHeight: ", imgFile.width, ",", imgFile.height,
                   "\n sdlRect: "
                   "(", sdl.nativeRect.w, ",", sdl.nativeRect.h, ",", sdl.nativeRect.x, ",", sdl.nativeRect.y, ")" );
#endif

    sdl.texture = IMG_LoadTexture( context.lock()->sdl.renderer, System::AsRelAssetPath( imagePath ).c_str() );

    if(sdl.texture == nullptr) {
        DebugLog::LogWithSDLError( std::string( "Unable to load image:" ), imagePath );
    }
}

// void Texture::RenderTo( const Position& targetPos ) const {
//
// }

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
