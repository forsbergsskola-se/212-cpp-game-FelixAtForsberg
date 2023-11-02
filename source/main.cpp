#include <cstdio>
#include <format>
#include <iostream>
#include <string>
#include <filesystem>

#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

#include "system/window.h"
#include "graphics/texture.h"
#include "system/debug_log.h"

namespace fs = std::filesystem;

//#include <SDL2_ttf/SDL_ttf.h>

//Loads individual image as texture

int main( int argc, char* args[] )
{

    Window* window = new Window();

    std::string imagePath = fs::path("resources/texture.png" );
    std::cout << "Looking for resource at " << imagePath << std::endl;
    const fs::path curWorkDir = fs::current_path();
    std::cout << "From " << curWorkDir  << std::endl;



    std::string fullPath = (fs::current_path() / imagePath).string();
    DebugLog::Log(std::string("Full path:"), fullPath);

    window->LoadImage(fullPath);

//    Texture texture = Texture(fullPath,  );
//    window

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
