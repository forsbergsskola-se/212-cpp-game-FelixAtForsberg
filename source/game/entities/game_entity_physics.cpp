#include "game_entity_physics.h"

namespace SDLGame {

    GameEntityPhysical::GameEntityPhysical(const std::filesystem::path &imagePath, const std::weak_ptr<RenderContext> &context)
    : GameEntityRenderable(imagePath, context) {

    }

    void GameEntityPhysical::PhysicsTick() {
    }
}
