#include <cstdio>
#include <filesystem>
#include <iostream>
#include <string>

#include <SDL.h>

#include "game/game_ui.h"
#include "game/scene.h"
#include "game/entities/entity_background.hpp"
#include "game/entities/entity_bottle.hpp"
#include "system/debug_log.hpp"
#include "system/window.h"

using namespace SDLGame;

namespace fs = std::filesystem;


int main() {
    // 16:10 value because mac
    const auto window = std::make_shared<Window>( 1040, 650 );

    // const auto newTexture = window->CreateTexture( "images/texture.png" );
    // window->RenderTexture( newTexture );

    //https://wiki.libsdl.org/SDL2/SDL_Event
    SDL_Event event;

    Scene scene { window->renderContext };
    scene.CreateEntity<EntityBackground>();


    int framerate;
    scene.uiManager.AddPersistentLabel();

    // std::weak_ptr<EntityBottle> bottle1 = scene.CreateEntity<EntityBottle>();
    // std::weak_ptr<EntityBottle> bottle2 = scene.CreateEntity<EntityBottle>();
    // std::weak_ptr<EntityBottle> bottle3 = scene.CreateEntity<EntityBottle>();

    // Position newPos = Position(50, 50);
    // std::weak_ptr<EntityBottle> bottlePos = scene.CreateEntity<EntityBottle>( newPos );


    scene.Render();

    // scene.RegisterEventHandler( std::unique_ptr<EventHandler>() );

    bool quitRequested = false;


    Uint64 frameTimeLast = SDL_GetTicks64();

    // short frameRate;

    while(!quitRequested) {

       // LAST = NOW;
       // NOW = SDL_GetPerformanceCounter();

        Uint64 frameTimeCur     = SDL_GetTicks64();
        const Uint64 frameDelta = frameTimeCur - frameTimeLast;
        frameTimeLast           = frameTimeCur;

        scene.TickEntities( frameDelta );

        while(SDL_PollEvent( &event ) != 0) {
            switch(event.type) {
                case SDL_MOUSEBUTTONDOWN:
                    if(event.button.button == SDL_BUTTON_LEFT) {
                        const float x = event.button.x;
                        const float y = event.button.y;
                        DebugLog::Log( "Click at: ", x, " ", y );
                        auto bottle = scene.CreateEntity<EntityBottle>( Position { x, y } );

                    }

                case SDL_KEYDOWN:

                    break;

                case SDL_QUIT:
                    quitRequested = true;
                    break;
            }

        }
        scene.Render();



        // scene.TickEntities( deltaTime );
        // SDL_Delay( 16 );

        // DebugLog::Log(frameTime, " - ", SDL_GetTicks64() );
        // timeFrameLast = SDL_GetPerformanceCounter();
    }
    return 0;
}
