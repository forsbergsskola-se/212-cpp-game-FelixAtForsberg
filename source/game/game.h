#pragma once

namespace SDLGame {

    struct Dimensions {
        int w, h;
    };

    struct Position {
        float x = 0, y = 0;
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
