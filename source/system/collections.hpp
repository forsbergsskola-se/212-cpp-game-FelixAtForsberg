#pragma once
#include "game/entities/game_entity.h"


namespace SDLGame::Collections {

    // hasher that can handle weak_ptr
    struct WeakPtrHash {
        std::size_t operator()( const std::weak_ptr<GameEntity>& wp ) const {
            const auto entPtr = wp.lock();
            return std::hash<std::shared_ptr<GameEntity>> { }( entPtr );
        }
    };

    // comparator that can handle weak_ptr
    struct WeakPtrEqual {
        bool operator()( const std::weak_ptr<GameEntity>& lhs,
                         const std::weak_ptr<GameEntity>& rhs ) const {
            return !lhs.owner_before( rhs ) && !rhs.owner_before( lhs );
        }
    };

}
