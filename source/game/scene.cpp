#include "scene.h"
#include "game/entities/game_entity_renderable.h"
#include "system/debug_log.hpp"


namespace SDLGame {
    Scene::Scene( const std::shared_ptr<RenderContext>& context ) : uiManager { context },
    // Scene::Scene( std::shared_ptr<RenderContext> context ) : uiManager { context },
                                                             Entities  { std::array<std::shared_ptr<GameEntity>, MAX_ENTITIES>() },
                                                             renderContext { std::weak_ptr(context) }
    {
        SDL_SetRenderDrawColor(renderContext.lock()->sdl.renderer, 0, 0, 0, 255);
    }


    // copy all entities texture to renderer (from render context)
    void Scene::RenderEntities() const {

        for (const auto &entSharedPtr : Entities) {

            // converting it to a weakpointer only to check it is a little bit awkward,
            // verify/make hash functions support both would be better

            const auto entWeakPtr = std::weak_ptr(entSharedPtr);
            const auto entLock = entWeakPtr.lock();

            if ( !entLock ) continue; // confirm that the entity exists
            if (skipRenderEntities.contains( entWeakPtr ) ) continue; // and it is renderable

            // we passed skipRenderEntities check so static_cast is ok
            const std::shared_ptr<GameEntityRenderable> renderableEnt = std::static_pointer_cast<GameEntityRenderable>( entLock );

            renderableEnt->RenderEntity();

            // alternative solutions to dynamic_cast that could be considered:
            //  isRenderable bool on 'GameEntity'
            //  move virtual RenderEntity() to GameEntity but have the implementation do nothing
            //  keeping separate collections of non-renderer and rendered entities (still needs to track order?)
            //  bitset/btifield tracking renderable

        }
    }

    void Scene::TickEntities(const Uint64 &frameDelta) const {

        std::cout << "Ticking, Tick Delta: " << frameDelta << std::endl;

        // could create an iterator for entities that only returns valid weak pointers directly?
        for (const auto &entSharedPtr : Entities) {
            const auto entWeakPtr = std::weak_ptr(entSharedPtr);

            if (const auto entLock = entWeakPtr.lock()) {
                entLock->Tick(frameDelta);
            } else {
                // DebugLog::LogError( "No ent lock for TickEntities entity" );
            }

        }
    }

    // call RenderPresent with current (renderContext) frame buffer
    void Scene::ClearCurrentRender() const {
        SDL_RenderClear( renderContext.lock()->sdl.renderer );
    }

    void Scene::DisplayCurrentRender() const {
        SDL_RenderPresent( renderContext.lock()->sdl.renderer );
    }

    void Scene::RenderUI() const {
        this->uiManager.Render();
    }

    void Scene::Render() const {
        ClearCurrentRender();
        RenderEntities();
        RenderUI();
        DisplayCurrentRender();
    }


}


//bool SDLGame::Scene::RegisterEventHandler(SDLGame::EventHandler eventHandler) {
//    this->
//}
