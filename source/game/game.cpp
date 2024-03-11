#include "game/game.h"


namespace SDLGame {



    Game::Game() {

    }

    //

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
}
