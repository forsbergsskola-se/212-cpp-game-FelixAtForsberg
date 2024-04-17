#pragma once

#include "game_entity_physics.h"
#include "game_entity_renderable.h"


namespace SDLGame {

    struct EntityBottle final : GameEntityPhysical {

        explicit EntityBottle( const std::weak_ptr<RenderContext>& context ) : GameEntityPhysical(texturePath, context) {

        }


        // std::filesystem::path const TexturePath() const override {
            // return std::filesystem::path("images/Bottle.png");
        // }

        inline static const std::filesystem::path texturePath = "images/Bottle.png";

    private:

        void Tick( const uint64_t& frameDelta ) override {

            // const Position nextPos = this->pos += Position(0, 0.1 * frameDelta);

            // velocity = distance / time
            // velocity = gravitational constant * time

            // distance = velocity * time


            // const auto newPos = Position{ this->pos.x, distance, };
            // this->pos   = newPos;


            // this->pos.y += 1 / frameDelta;

            // DebugLog::LogMagenta(
                // "Bottle tick: ",
                // "\n  FrameDelta: ",  frameDelta,
                // "\n  Current Pos: ", pos, ", "
                // "\n     Next Pos: ", nextPos );

            // Destroy();
        }

        void PhysicsTick() override {
            this->pos.y += 1;
        }

        // void Destroy() const {
        //     delete this;
        // }
    };
}
