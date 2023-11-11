#include <cstdio>
#include <format>
#include <iostream>
#include <string>
#include <filesystem>

#include <SDL.h>
#include <SDL2_image/SDL_image.h>

#include "system/window.h"
#include "graphics/texture.h"
#include "system/debug_log.hpp"

using namespace SDLGame;

namespace fs = std::filesystem;

//#include <SDL2_ttf/SDL_ttf.h>

int main()
{

    Window* window = new Window();

    auto newTexture = window->CreateTexture("texture.png");
    window->RenderTexture(newTexture);

    bool quit = false;

    SDL_Event e;

    //While application is running
    while( !quit )
    {
        while( SDL_PollEvent( &e ) != 0 )
        {
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }

    }
	return 0;
}
