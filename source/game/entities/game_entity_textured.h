#pragma once
#include "../game.h"
#include "../../graphics/texture.h"
#include "game_entity.h"


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
