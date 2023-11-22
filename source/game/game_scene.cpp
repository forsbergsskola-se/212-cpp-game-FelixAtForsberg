#include "game/game_scene.h"
#include "system/debug_log.hpp"


namespace SDLGame {

    constexpr bool LOG_SCENE_ENTITY_CREATION = true;


    Scene::Scene( const std::shared_ptr<RenderContext>& context ) : renderContext( context ),
                                                                    Entities( std::array<std::shared_ptr<GameEntity>, MAX_ENTITIES>() ) {

    }

    // create a entity and optionally return
    // an upcast reference to its shared pointer
    template <IsGameEntity TEntity> std::shared_ptr<TEntity> Scene::CreateEntity() {
        if(LOG_SCENE_ENTITY_CREATION) {
            DebugLog::Log( "[CreateEntity]" );
        }
        // could use 2048 bits, 256 bytes to represent empty spots
        // and do bytewise -> bitwise binary search on since
        // on smallest addressible, heck I'll get some type punning going


        auto newEntity            = std::make_shared<TEntity>();
        Entities.at( entsTail++ ) = newEntity;
        return newEntity;
    }


}


//bool SDLGame::Scene::RegisterEventHandler(SDLGame::EventHandler eventHandler) {
//    this->
//}
