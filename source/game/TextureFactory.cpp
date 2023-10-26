#include "TextureFactory.h"

// Takes an image path and loads it, converts it to a surface
SDL_Surface* TextureFactory::CreateSurface(std::string &path) {

    SDL_Surface* newSurface;

//  Alternatively, could load an error texture
    if( !(newSurface = IMG_Load(path.c_str())) )
        error::FatalErrorExit(std::string{"Unable to load image: "}.append(path) );

    if ( !(newSurface = SDL_ConvertSurface(newSurface, TextureFactory::Format, 0)) )
        error::FatalErrorExit(std::string{"Unable to convert to surface: "}.append(path));

    return newSurface;
}

// Creates a texture from an image path
SDL_Texture* TextureFactory::CreateTexture(std::string &path) {
    SDL_Surface* newSurface { TextureFactory::CreateSurface(path) };
    SDL_Texture* newTexture;

    newTexture = SDL_CreateTextureFromSurface(TextureFactory::Renderer, newSurface);
    if (!newTexture)
        error::FatalErrorExit(std::string{"Unable to create texture: "}.append(path));

    SDL_FreeSurface(newSurface);

    return newTexture;
}