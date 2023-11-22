#pragma once

#include <memory>
#include <functional>

#include <SDL_events.h>


namespace SDLGame {


    // if only variant used named fields ugh, WHY C++ COMMITTEE, WHY???
    // YOU ABSOLUTE BUFFOONS
    //        using MouseClick = std::variant<int, int>;


//    struct EventData {
//    protected:
//        EventData() = delete;
//    };


    // ------------ EventData

    struct EventDataInterface {
        virtual ~EventDataInterface() = 0;

    };

    // EventDataInterface::~EventDataInterface() {};
    using Event = EventDataInterface;


    struct EventMouse : EventDataInterface {
        int x, y;
    };

    struct EventKey : EventDataInterface  {
        int keyCode;
    };

    // ----------------------- Event

    template <typename T>
    concept eventData = std::is_base_of_v<EventDataInterface, T>;


    // ----------------------- EventHandler

    //    template<EventData T>
    //    struct Event {
    //        T data;
    //    };


//    template <eventData TEventData>

    struct EventHandlerInterface {
        virtual ~EventHandlerInterface() = 0;

    };


    //TODO:
    struct EventHandler : EventHandlerInterface {

        SDL_Event trigger;

        // event (and data) we're wrapping
        const std::unique_ptr<Event> event;

        std::function<void()> callback;

    };

}

//https://wiki.libsdl.org/SDL2/SDL_AddEventWatch
// ^ seems to be primarily for modifying events as they happen




