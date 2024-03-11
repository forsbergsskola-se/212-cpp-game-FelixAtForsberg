#pragma once
#include <ostream>
#include <SDL_rect.h>

namespace SDLGame {

    struct Dimensions {
        int w, h;

        // allow construction of SDL_Rect from Dimensions
        explicit operator SDL_Rect() const {
            return {0,0, w, h};
        }
    };

    struct Position {
        int x = 0, y = 0;

        explicit Position(const float x = 0, const float y = 0) : x(x), y(y) {}

        friend std::ostream& operator<<(std::ostream& lhs, const Position& rhs);

        Position& operator+=(const Position& rhs);

    };

    struct PositionedRect {
        Position pos;
        Dimensions size;

        // allow construction of SDL_Rect from PositionedRect
        explicit operator SDL_Rect() const {
            return {pos.x, pos.y, size.w, size.h};
    }

        // explicit operator SDL_Rect*() const {
        // SDL_Rect* rect = new SDL_Rect{0, 0,0, 0};
        // return rect;
        // }

    };

    class Game {

        Game();
    };

}


//    constexpr size_t LOADED_SCENES_MAX = 8;

//    struct Game_t {
//        Game_t() = default;
//
//        std::array<std::reference_wrapper<Scene>, LOADED_SCENES_MAX> LoadedScenes;
//    } Game;
