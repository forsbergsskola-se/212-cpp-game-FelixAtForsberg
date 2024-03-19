#pragma once

#include "game_entity_renderable.h"


namespace SDLGame {

    // Entity that simply acts the background
    // Note: does not stretch to fit window; uses native image size
    struct EntityBackground final : GameEntityRenderable {

        explicit EntityBackground( const std::weak_ptr<RenderContext>& context ) : GameEntityRenderable(texturePath, context) {

        }


        // std::filesystem::path const TexturePath() const override {
            // return std::filesystem::path("images/Bottle.png");
        // }

        inline static const std::filesystem::path texturePath = "images/Background.png";

    private:

        void Tick( const uint64_t& ) override {

        }


    };
}
