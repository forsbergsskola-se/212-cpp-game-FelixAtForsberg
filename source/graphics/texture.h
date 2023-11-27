#pragma once
#include <filesystem>

#include "game/game.h"
#include "render_context.hpp"
#include "system/debug_log.hpp"


#define LOG_TEXTURE

namespace SDLGame {
        struct Texture {

        Texture(const std::filesystem::path& imagePath, const std::weak_ptr<RenderContext>& context);

        Dimensions      size;

        const std::weak_ptr<RenderContext>   renderContext;


        struct sdl_texture_t {
            SDL_Rect        nativeRect;
            SDL_Texture*    texture;
        } sdl;


    };
}

