#include "game/entities/game_entity_textured.h"


SDLGame::GameEntityTextured::GameEntityTextured(const Texture& tex) : nativeSize(tex.size), texture( tex ) {
}
