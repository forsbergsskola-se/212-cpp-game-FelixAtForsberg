#include <cstdio>
#include <format>
#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include "system/window.h"
//#include <SDL2_ttf/SDL_ttf.h>

//Loads individual image as texture

int main( int argc, char* args[] )
{
    Window* newWindow = new Window();
    newWindow->LoadImageFromPath("source/texture.png");

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
