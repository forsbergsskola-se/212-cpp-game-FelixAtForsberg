#pragma once
#include <filesystem>

#include "game/game.h"
#include "render_context.hpp"
#include "system/debug_log.hpp"


#define LOG_TEXTURE

namespace SDLGame {
    struct Texture {

        Texture(const std::filesystem::path& imagePath, const std::shared_ptr<RenderContext>& context);

        void RenderTo( const Position& targetPos ) const;

        Dimensions      size;

        const std::shared_ptr<RenderContext>   renderContext;


        struct sdl_texture_t {
            SDL_Rect        nativeRect;
            SDL_Texture*    texture;
        } sdl;


    };
}

