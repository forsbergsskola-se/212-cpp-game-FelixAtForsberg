#include <cstdio>
#include <format>
#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "system/window.h"
#include "graphics/texture_factory.h"
#include "system/debug_prints.h"

//#include <SDL2_ttf/SDL_ttf.h>

//Loads individual image as texture

    int main( int argc, char* args[] )
{
    auto* newWindow = new Window();

    std::string imagePath = std::string("source/texture");
    newWindow->SetWindowImage(imagePath);

    // when you have support for textures
    // TODO 3: add support for game objects (textures and positions and sizes)
    // TODO 4: maybe add a scene class (that holds and renders all game objects)
    // TODO 5: see, if you can make it that you can move two images separately using buttons, e.g. arrow keys and WASD

    //Main loop flag
    bool quit = false;

    //Event handler
    SDL_Event e;

    //While application is running
    while( !quit )
    {
        //Handle events on queue
        while( SDL_PollEvent( &e ) != 0 )
        {
            //User requests quit
            if( e.type == SDL_QUIT )
            {
                quit = true;
            }
        }

    }
	return 0;
}
