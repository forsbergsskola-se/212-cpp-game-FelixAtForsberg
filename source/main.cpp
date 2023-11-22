#include <cstdio>
#include <filesystem>
#include <iostream>
#include <string>

#include <SDL.h>

#include "game/game_scene.h"
#include "game/entities/entity_bottle.hpp"
#include "graphics/texture.h"
#include "system/debug_log.hpp"
#include "system/window.h"

using namespace SDLGame;

namespace fs = std::filesystem;


int main() {
    const Window* window = new Window();

    const auto newTexture = window->CreateTexture( "images/texture.png" );
    window->RenderTexture( newTexture );

    //https://wiki.libsdl.org/SDL2/SDL_Event
    SDL_Event event;


    Scene scene { window->renderContext };


    const auto bottleTexture = window->CreateTexture(  );

    std::shared_ptr<EntityBottle> bottle = scene.CreateEntity<EntityBottle>();

    // scene.RegisterEventHandler( std::unique_ptr<EventHandler>() );

    bool quitRequested = false;

    while(!quitRequested) {
        while(SDL_PollEvent( &event ) != 0) {
            switch(event.type) {
                case SDL_MOUSEBUTTONDOWN:
                    if(event.button.button == SDL_BUTTON_LEFT) {
                        int x = event.button.x;
                        int y = event.button.y;
                        DebugLog::Log( "Click at: ", x, " ", y );
                    }
                case SDL_KEYDOWN:

                    break;

                case SDL_QUIT:
                    quitRequested = true;
                    break;
            }

        }
    }
    return 0;
}
