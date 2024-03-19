#include "game/game.h"


namespace SDLGame {


    // ------------ Game ------------

    Game::Game() {

    }

    // ------------ Dimensions ------------

    Dimensions::Dimensions(): w{0}, h{0} {}
    Dimensions::Dimensions( const int w, const int h ): w{w}, h{h} {}

    Dimensions::operator SDL_Rect() const {
        return {0,0, w, h};
    }



    // ------------ Position ------------

    Position::Position( const decltype(x) x, const decltype(y) y ) :
    x{x}, y{y}
    {}

    Position::Position( const float x, const float y ) :
    x{static_cast<int>(x)}, y{ static_cast<int>(y) }
    {}

    Position& Position::operator+=( const Position& rhs ) {
        this->x += rhs.x;
        this->y += rhs.y;
        return *this;
    }

    std::ostream& operator<<( std::ostream& lhs, const Position& rhs ) {
        lhs << "("  << rhs.x;
        lhs << ", " << rhs.y;
        lhs << ")";
        return lhs;
    }

    // ------------ Bounds ------------

    Bounds::Bounds():
        pos{0,0},
        size{0,0} {}

    Bounds::Bounds( const float x, const float y, const int w, const int h ):
        pos{x, y},
        size{w, h} {}


    Bounds::Bounds( const Position pos, const Dimensions size ) :
        pos{pos},
        size{size} {}


    Bounds::Bounds( const SDL_Rect& sdlRect ) :
        pos{ static_cast<float>(sdlRect.x), static_cast<float>(sdlRect.y) },
        size{ sdlRect.w, sdlRect.h } {}


    Bounds::operator SDL_Rect() const {
        return {pos.x, pos.y, size.w, size.h};
    }



}
