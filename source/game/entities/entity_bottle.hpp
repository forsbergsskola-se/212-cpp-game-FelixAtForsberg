#pragma once

#include "game_entity_renderable.h"


namespace SDLGame {

    struct EntityBottle final : GameEntityRenderable {

        explicit EntityBottle( const std::weak_ptr<RenderContext>& context ) : GameEntityRenderable(texturePath, context) {

        }


        // std::filesystem::path const TexturePath() const override {
            // return std::filesystem::path("images/Bottle.png");
        // }

        inline static const std::filesystem::path texturePath = "images/Bottle.png";

    private:

        void Tick() override {

        }
    };
}
