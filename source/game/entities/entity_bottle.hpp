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

        void Tick( const double& frameDelta ) override {


            // const Position nextPos = this->pos += Position(0, 0.1 * frameDelta);


            this->pos += Position(0, 0.1 * frameDelta);


            // this->pos.y += 1 * frameDelta;

            // DebugLog::LogMagenta(
                // "Bottle tick: ",
                // "\n  FrameDelta: ",  frameDelta,
                // "\n  Current Pos: ", pos, ", "
                // "\n     Next Pos: ", nextPos );

            // Destroy();
        }

        // void Destroy() const {
        //     delete this;
        // }
    };
}
