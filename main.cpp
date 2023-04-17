#include <SDL.h>
#include <cstdio>
#include "cmake-build-debug/system/window.h"
#include "source/system/error.h"
#include <string>

using std::string;

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        error::FatalErrorExit(string("Unable to initialize video subsystem"));

    Window window{ string{"SDL Tutorial"}};


        SDL_FillRect(window.Surface, nullptr, SDL_MapRGB(window.Surface->format, 0xFF, 0xFF, 0xFF));
        window.Update();


//        //Hack to get window to stay up
        SDL_Event e;
        bool quit = false;
        while (quit == false) {
            while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; }
    }

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}