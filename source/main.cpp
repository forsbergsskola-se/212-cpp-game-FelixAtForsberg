#include <cstdio>
#include <filesystem>
#include <iostream>
#include <queue>
#include <string>

#include <SDL.h>

#include "game/game_ui.h"
#include "game/scene.h"
#include "game/entities/entity_background.hpp"
#include "game/entities/entity_bottle.hpp"
#include "system/debug_log.hpp"
#include "system/framecounter.hpp"
#include "system/window.h"

using namespace SDLGame;
using namespace std::literals::string_literals;

namespace fs = std::filesystem;

using std::chrono::steady_clock;
using time_point = steady_clock::time_point;


int main() {
    // 16:10 value because mac
    const auto window = std::make_shared<Window>( 1040, 650 );

    //https://wiki.libsdl.org/SDL2/SDL_Event
    SDL_Event event;

    Scene scene { window->renderContext };
    scene.CreateEntity<EntityBackground>();

    auto frameCounter = FrameCounter{};
    uint bottlesSpawned = 0;

    constexpr std::chrono::microseconds updateFrameLabelDelta = 500ms; // update framerate labels every x ms
    time_point lastFrameLabelUpdate = steady_clock::now();


    const auto labelFrameCounterBufferSize         = scene.uiManager.AddPersistentLabel();

    labelFrameCounterBufferSize.SetText("Memorized Frame Times: "s + std::to_string( frameCounter.BufferCapacity ));

    const auto labelFrametimeAvg         = scene.uiManager.AddPersistentLabel();
    const auto labelFrametime      = scene.uiManager.AddPersistentLabel();
    const auto labelFPS      = scene.uiManager.AddPersistentLabel();
    const auto labelFPSAvg      = scene.uiManager.AddPersistentLabel();


    const auto labelBottlesSpawned = scene.uiManager.AddPersistentLabel();

    // std::weak_ptr<EntityBottle> bottle1 = scene.CreateEntity<EntityBottle>();
    // std::weak_ptr<EntityBottle> bottle2 = scene.CreateEntity<EntityBottle>();
    // std::weak_ptr<EntityBottle> bottle3 = scene.CreateEntity<EntityBottle>();

    // Position newPos = Position(50, 50);
    // std::weak_ptr<EntityBottle> bottlePos = scene.CreateEntity<EntityBottle>( newPos );


    // scene.RegisterEventHandler( std::unique_ptr<EventHandler>() );

    bool quitRequested = false;

    time_point lastEntityTick;

    while(!quitRequested) {

        frameCounter.FrameStart();

        std::chrono::nanoseconds entsDeltaTime = steady_clock::now() - lastEntityTick;

        scene.TickEntities( entsDeltaTime.count() );
        lastEntityTick = steady_clock::now();


        while(SDL_PollEvent( &event ) != 0) {
            switch(event.type) {
                case SDL_MOUSEBUTTONDOWN:
                    if(event.button.button == SDL_BUTTON_LEFT) {
                        const float x = event.button.x;
                        const float y = event.button.y;
                        DebugLog::Log( "Click at: ", x, " ", y );
                        auto bottle = scene.CreateEntity<EntityBottle>( Position { x, y } );
                        bottlesSpawned++;
                    }

                case SDL_KEYDOWN:

                    break;

                case SDL_QUIT:
                    quitRequested = true;
                    break;
            }

        }
        scene.Render();
        frameCounter.FrameEnd();

        // Set label text
        labelBottlesSpawned.SetText( "Bottles spawned: "s + std::to_string(bottlesSpawned) );



        if ( frameCounter.FrameStartTime > (lastFrameLabelUpdate + updateFrameLabelDelta)) {
            lastFrameLabelUpdate = frameCounter.FrameStartTime;

               labelFrametime.SetText( "Frametime     (ms): "s + std::to_string( frameCounter.FrameTimeLast().count() ) );
            labelFrametimeAvg.SetText( "Frametime Avg (ms): "s + std::to_string( frameCounter.FrameTimeAverage().count() )  );

                     labelFPS.SetText( "FPS: "s     + std::to_string( frameCounter.FPS() ) );
                  labelFPSAvg.SetText( "FPS Avg: "s + std::to_string( frameCounter.FPSAverage() ) );

        }


        // scene.TickEntities( deltaTime );
        // SDL_Delay( 16 );

        // DebugLog::Log(frameTime, " - ", SDL_GetTicks64() );
        // timeFrameLast = SDL_GetPerformanceCounter();
    }
    return 0;
}
