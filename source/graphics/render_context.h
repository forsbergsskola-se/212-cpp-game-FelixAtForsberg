#pragma once
#include <algorithm>

#include <SDL_render.h>


namespace SDLGame {

    struct RenderContext {

         struct RenderContextSDL {
            SDL_Renderer* renderer;
            SDL_Surface* surface;

            RenderContextSDL(SDL_Renderer* renderer, SDL_Surface* surface);
            RenderContextSDL() = default;
        };

        std::shared_ptr<RenderContextSDL> sdl;

        RenderContext(SDL_Renderer* otherRenderer, SDL_Surface* otherSurface) {
            this->sdl->renderer = otherRenderer;
            this->sdl->surface = otherSurface;
        }

    };
}
