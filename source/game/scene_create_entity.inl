#pragma once

#include "game/entities/game_entity_renderable.h"

namespace SDLGame {

    template <IsGameEntity TEntity>
    std::weak_ptr<TEntity> Scene::CreateEntity() {
        if(LOG_SCENE_ENTITY_CREATION) {
            DebugLog::Log( "[CreateEntity]" );
        }
        // could use 2048 bits, 256 bytes to represent empty spots
        // and do bytewise -> bitwise binary search on since
        // on smallest addressible, heck I'll get some type punning going

        const std::shared_ptr<TEntity> derivedPtr = std::make_shared<TEntity>( renderContext );
        const auto baseEntityPtr = std::static_pointer_cast<GameEntity>( derivedPtr );
        Entities.at( entsTail++ ) = baseEntityPtr;

        auto entDerivedWkPtr = std::weak_ptr<TEntity>( static_pointer_cast<TEntity>(baseEntityPtr) );


        if (auto asRenderableEnt = std::dynamic_pointer_cast<GameEntityRenderable>(baseEntityPtr); !asRenderableEnt.get())
            skipRenderEntities.insert( asRenderableEnt );

        return entDerivedWkPtr;
    }

}
