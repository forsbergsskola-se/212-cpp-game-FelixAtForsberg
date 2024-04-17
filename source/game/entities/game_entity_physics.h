#pragma once
#include "game_entity_renderable.h"

namespace SDLGame {


class GameEntityPhysical : public GameEntityRenderable {

public:
    GameEntityPhysical(const std::filesystem::path &imagePath, const std::weak_ptr<RenderContext> &context);

private:


        // Occurs before Tick
        // Runs 0 or as many times as it needs to catch up to framerate
        virtual void PhysicsTick();

    };
}
