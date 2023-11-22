#pragma once
#include <algorithm>

#include <SDL_render.h>


namespace SDLGame {

    struct RenderContext {

        RenderContext( SDL_Renderer* renderer, SDL_Surface* surface ) : sdl( renderer, surface ) {

        }


        struct RenderContextSDL_t {
            RenderContextSDL_t( SDL_Renderer* renderer, SDL_Surface* surface ) :
            renderer( renderer ),
            surface( surface ) {

            }

            SDL_Renderer* renderer;
            SDL_Surface* surface;
        } const sdl;
        // } const sdl;
        // const RenderContextSDL_t sdl;
        // = RenderContextSDL_t(renderer, surface);

    };
}
