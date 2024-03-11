#pragma once

#include "game/entities/game_entity_renderable.h"

namespace SDLGame {

    template <IsGameEntity TEntity>
    std::weak_ptr<TEntity> Scene::CreateEntity() {
        if(LOG_SCENE_ENTITY_CREATION) {
            DebugLog::Log( "[CreateEntity] Creating" );
        }
        // could use 2048 bits, 256 bytes to represent empty spots
        // and do bytewise -> bitwise binary search on since
        // on smallest addressible, heck I'll get some type punning going and
        // const Scene& scene = *this;
        const std::shared_ptr<TEntity> derivedPtr = std::make_shared<TEntity>( renderContext );
        const auto baseEntityPtr = std::static_pointer_cast<GameEntity>( derivedPtr );
        Entities.at( entsTail++ ) = baseEntityPtr;

        auto entDerivedWkPtr = std::weak_ptr<TEntity>( static_pointer_cast<TEntity>( baseEntityPtr ) );


        if (auto asRenderableEnt = std::dynamic_pointer_cast<GameEntityRenderable>(baseEntityPtr); !asRenderableEnt.get())
            skipRenderEntities.insert( asRenderableEnt );

        return entDerivedWkPtr;
    }



    // Create Entity at Position
    template <HasPositionField TEntity>
    std::weak_ptr<TEntity> Scene::CreateEntity(const Position pos) {

        if(LOG_SCENE_ENTITY_CREATION)
            DebugLog::Log( "[CreateEntity] Position Overload Invoked: ", pos.x, ", ", pos.y );


        auto entWkPtr = Scene::CreateEntity<TEntity>();
        if(const auto ent = entWkPtr.lock()) {

            ent->pos.x = pos.x;
            ent->pos.y = pos.y;

        }

        return entWkPtr;
    }

}
