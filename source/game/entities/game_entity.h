#pragma once

#include "system/system_static.h"
#include "system/event/events.h"


// when you have support for textures
// TODO 3: add support for game objects (textures and positions and sizes)
// TODO 4: maybe add a scene class (that holds and renders all game objects)
// TODO 5: see, if you can make it that you can move two images separately using buttons, e.g. arrow keys and WASD

namespace SDLGame {


    class GameEntity {
    protected:
        virtual ~GameEntity() = 0;

    public:
        explicit GameEntity();


        std::deque<std::unique_ptr<Event>> EventQueue;

virtual void SpawnAt(int x, int y) {}

        virtual void Tick() = 0;
        bool physicsUseGravity = true;

        virtual void Destroy() {}
    };

}

