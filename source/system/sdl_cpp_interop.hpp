#pragma once
#include <SDL_render.h>
#include <SDL_surface.h>




// arguably even better and less repitious would be:
//  https://stackoverflow.com/a/51274008/23129719

// allows alternative to:
//  decltype(&SDL_FreeSurface) = void (*)(SDL_Surface*)  --- type/signature of deleter function
//  std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> surface;
//   ^ becomes v :
//  std::unique_ptr<SDL_Surface, SDLSurfaceDeleter> surface;

// https://stackoverflow.com/a/19054280/23129719
struct SDLSurfaceDeleter {
    constexpr void operator()(SDL_Surface* surface) const { SDL_FreeSurface( surface ); }
};

// allows alternative to:
//  std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture; // texture we create from cached surface
//   ^ becommes v :
//  std::unique_ptr<SDL_Texture, SDLTextureDeleter> surface;
//

struct SDLTextureDeleter {
    constexpr void operator()(SDL_Texture* texture) const { SDL_DestroyTexture( texture ); }
};




