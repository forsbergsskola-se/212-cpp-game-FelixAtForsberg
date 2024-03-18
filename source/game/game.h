#pragma once
#include <ostream>
#include <SDL_rect.h>

namespace SDLGame {

    struct Dimensions {
        explicit Dimensions();
        explicit Dimensions( int w, int h);

        int w, h;

        // allow construction of SDL_Rect from Dimensions
        explicit operator SDL_Rect() const;
    };

    struct Position {
        int x = 0, y = 0;

        explicit Position(const float x = 0, const float y = 0);


        friend std::ostream& operator<<(std::ostream& lhs, const Position& rhs);

        Position& operator+=(const Position& rhs);

    };

    struct Bounds {
        Position pos;
        Dimensions size;


        explicit Bounds();

        explicit Bounds( float x, float y, int w, int h);

        explicit Bounds( Position pos, Dimensions size);

        explicit Bounds( const SDL_Rect& sdlRect );

        // allow construction of SDL_Rect from Bounds
        explicit operator SDL_Rect() const;



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
