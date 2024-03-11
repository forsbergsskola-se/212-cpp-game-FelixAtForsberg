#pragma once
#include <algorithm>

#include <SDL_render.h>

#include "system/debug_log.hpp"


namespace SDLGame {
    struct RenderContext {
        RenderContext( SDL_Renderer* renderer, SDL_Surface* surface ) : sdl( renderer, surface ) {}

        ~RenderContext() {
            DebugLog::Log("RenderContext Destroyed");
        }

        struct SDLRenderContext {
            SDLRenderContext( SDL_Renderer* renderer, SDL_Surface* surface ) :
            renderer( renderer ),
            surface( surface ) {}

            ~SDLRenderContext() {
                DebugLog::Log("SDLRenderContext Destroyed");
            }

            SDL_Renderer* renderer;
            SDL_Surface* surface;
        } const sdl;
    };
}
