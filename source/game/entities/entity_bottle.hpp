
#include "game_entity.h"
#include "game_entity_textured.h"

namespace SDLGame {

    class EntityBottle final : GameEntityTextured {

        inline static const std::filesystem::path texturePath = "images/bottle.png";
        // Bottle() : GameEntityTextured() {

        // };

    public:

        explicit EntityBottle( const Texture& tex )
        : GameEntityTextured( tex ) {
        }

    private:

        void Tick() override {

        }
    };

}
