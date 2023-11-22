#pragma once
#include "game/game.h"
#include "game/entities/game_entity.h"
#include "graphics/texture.h"


namespace SDLGame {

    class GameEntityTextured : public GameEntity {

    public:

        explicit GameEntityTextured( const std::filesystem::path& texturePath );
        explicit GameEntityTextured( const Texture& tex );

        Position pos;

        const Dimensions nativeSize;
        Texture texture;
        static const std::filesystem::path texturePath;
    };

}
