#pragma once
#include "game/game.h"
#include "game/entities/game_entity.h"
#include "graphics/texture.h"


namespace SDLGame {
    // Using an interface like "IRenderable" could be cleaner?

    class GameEntityRenderable : public GameEntity {

    protected:
        ~GameEntityRenderable() override = default;

    public:

        // explicit GameEntityRenderable( const std::filesystem::path& imagePath, const std::weak_ptr<RenderContext>& context );


        GameEntityRenderable( const std::filesystem::path& imagePath, const std::weak_ptr<RenderContext>& context );


        virtual void RenderEntity();

        Position pos;

        // virtual std::filesystem::path TexturePath() const = 0;
        const std::filesystem::path texturePath;

        const std::shared_ptr<Texture> texture;
    };


}
