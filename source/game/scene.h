#pragma once
#include <array>
#include <unordered_set>
#include <type_traits>

#include "game/game_ui.h"
#include "game/entities/game_entity.h"
#include "game/input/game_input.h"
#include "graphics/render_context.hpp"
#include "system/collections.hpp"


namespace SDLGame {
    struct Position;

    constexpr size_t MAX_ENTITIES = 2048;
    constexpr bool LOG_SCENE_ENTITY_CREATION = true;


    template <typename T>
    concept HasElementType   = requires { typename T::element_type; };

    template <typename T>
    concept IsGameEntity     = requires { std::derived_from<T, GameEntity>; };

    template <typename T>
    concept IsGameEntityPtr  = requires { std::derived_from<typename T::element_type, GameEntity>; };

    template <typename T>
    concept HasPositionField = requires(T a) {
        { std::is_same_v<T, int> };
    };

    class Scene {

    public:

        explicit Scene(const std::shared_ptr<RenderContext>& context );
        // explicit Scene( std::shared_ptr<RenderContext> context );


        template <IsGameEntity TEntity>
        std::weak_ptr<TEntity> CreateEntity();


        template <HasPositionField TEntity>
        std::weak_ptr<TEntity> CreateEntity( Position pos );

        UIManager uiManager;

        void RenderEntities() const;


        void DisplayCurrentRender() const;


        void RenderUI() const;


        void TickEntities( const uint64_t frameDelta ) const;


        void ClearCurrentRender() const;


        void Render() const;




        // create a entity and optionally return
    // an upcast reference to its shared pointer


        // stores results of dynamic_pointer_cast'ing on entity creation
        // store skippable instead of renderable because most entities will be renderable
        std::unordered_set<std::weak_ptr<GameEntity>, Collections::WeakPtrHash, Collections::WeakPtrEqual> skipRenderEntities;
        std::array<std::shared_ptr<GameEntity>, MAX_ENTITIES> Entities { nullptr };


        // Used when creating entities, contains the window renderer reference that the GameEntityRenderable's texture needs.
        const std::weak_ptr<RenderContext> renderContext;

    private:

        size_t entsTail = 0;



        // bool RegisterEventHandler( std::unique_ptr<EventHandler> );
    };


}
#include "scene_create_entity.inl"
