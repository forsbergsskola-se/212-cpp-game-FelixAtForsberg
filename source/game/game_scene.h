#pragma once
#include <array>
#include "game/entities/game_entity.h"
#include "game/input/game_input.h"
#include "graphics/render_context.h"
#include "system/event/events.h"


namespace SDLGame {

    constexpr size_t MAX_ENTITIES = 2048;

    template <typename T>
    concept HasElementType = requires { typename T::element_type; };

    template <typename T>
    concept IsGameEntity = requires { std::derived_from<T, GameEntity>; };

    template <typename T>
    concept IsGameEntityPtr = requires { std::derived_from<typename T::element_type, GameEntity>; };

    class Scene {

    public:

        explicit Scene( RenderContext context );

        std::array<std::shared_ptr<GameEntity>, MAX_ENTITIES> Entities { nullptr };

        template <IsGameEntity TEntity>
        std::shared_ptr<TEntity> CreateEntity();

        RenderContext renderContext;


    private:

        size_t entsTail = 0;

        // bool RegisterEventHandler( std::unique_ptr<EventHandler> );
    };


}
