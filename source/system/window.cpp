#include <array>
#include <iostream>

#include <SDL_video.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

#include "system/window.h"
#include "graphics/texture.h"
#include "system/debug_log.hpp"

using namespace SDLGame;

//Screen dimension constants

//constexpr SDL_WindowFlags INITIAL_WINDOW_FLAGS = SDL_WINDOW_INPUT_FOCUS;

constexpr std::array<uint8_t, 4> INITIAL_RENDERER_COLOR { 255, 255, 255, 255 };

Window::Window(const int& width, const int& height ) {


    SDL_Init( SDL_INIT_VIDEO );

    //Initialize PNG loading
    if(constexpr int imgFlags = IMG_INIT_PNG; !(IMG_Init( imgFlags ) & imgFlags))
        DebugLog::LogError( "SDL_image could not initialize! SDL_image Error: ", IMG_GetError() );

    if(TTF_Init() < 0)
        DebugLog::LogError( "Could not initialize SDL_ttf, Error:", TTF_GetError() );

    if(!SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ))
        DebugLog::LogError( "Warning: Linear texture filtering not enabled!" );


    sdlWindow = SDL_CreateWindow(
                                 "SDLGame",
                                 SDL_WINDOWPOS_UNDEFINED,
                                 SDL_WINDOWPOS_UNDEFINED,
                                 width,
                                 height,
                                 SDL_WINDOW_SHOWN
                                );

    if(sdlWindow == nullptr) {
        DebugLog::LogWithSDLError( "window could not be created!" );
    }

    SDL_Renderer* windowRenderer = SDL_CreateRenderer( sdlWindow, -1, SDL_RENDERER_SOFTWARE );
    if(windowRenderer == nullptr) {
        DebugLog::LogWithSDLError( "Could not create a renderer" );
    }

    SDL_Surface* windowSurface = SDL_GetWindowSurface( sdlWindow );
    if(windowSurface == nullptr) {
        DebugLog::LogWithSDLError( "Could not retrieve window surface" );
    }

    renderContext = std::make_shared<RenderContext>( windowRenderer, windowSurface );


    SDL_SetRenderDrawColor( windowRenderer, 0x1b, 0x1b, 0x1b, 0xFF );
}

Window::~Window() {
    DebugLog::Log("Window was destroyed");
    //Destroy window
    SDL_DestroyWindow( sdlWindow );
    sdlWindow     = nullptr;
    renderContext = nullptr;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}
