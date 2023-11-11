#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL_video.h>

#include <iostream>
#include <string>
#include <cstdio>
#include <array>

#include "window.h"
#include "../graphics/texture.h"
#include "debug_log.hpp"

using namespace SDLGame;

//Screen dimension constants

//constexpr SDL_WindowFlags INITIAL_WINDOW_FLAGS = SDL_WINDOW_INPUT_FOCUS;

constexpr std::array<uint8_t, 4> INITIAL_RENDERER_COLOR {255, 255, 255, 255};

Window::Window() {

    SDL_Init( SDL_INIT_VIDEO );

    //Initialize PNG loading
    int const imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        DebugLog::Log("SDL_image could not initialize! SDL_image Error: ", IMG_GetError());
    }

    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        DebugLog::Log("Warning: Linear texture filtering not enabled!");
    }

    sdlWindow = SDL_CreateWindow(
            "SDLGame",
            SDL_WINDOWPOS_UNDEFINED,
            SDL_WINDOWPOS_UNDEFINED,
            SCREEN_WIDTH,
            SCREEN_HEIGHT,
            SDL_WINDOW_SHOWN
            );

    if (sdlWindow == nullptr) {
        DebugLog::LogWithSDLError("window could not be created!");
    }

    windowRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_SOFTWARE);
    if (windowRenderer == nullptr) {
        DebugLog::LogWithSDLError("Could not create a renderer");
    }

    SDL_SetRenderDrawColor(windowRenderer, 0xff, 0xff , 0xff, 0xff);


    windowSurface = SDL_GetWindowSurface(sdlWindow);
    if (windowSurface == nullptr) {
        DebugLog::LogWithSDLError("Could not retrieve window surface");
    }

//    windowFormat = SDL_GetWindowPixelFormat(sdlWindow);

//    Initialize renderer color
    SDL_SetRenderDrawColor( windowRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
    

}

Window::~Window()
{
    std::cout << "window was destroyed";
	//Destroy window
	SDL_DestroyRenderer(windowRenderer );
	SDL_DestroyWindow( sdlWindow );
	sdlWindow = nullptr;
    windowRenderer = nullptr;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

Texture Window::CreateTexture(const std::filesystem::path& imageName)
{
    const Texture newTexture = Texture(windowRenderer, imageName);
    return newTexture;
}

void Window::RenderTexture(const Texture& texture) {

    SDL_RenderClear(windowRenderer);
    SDL_SetRenderDrawColor(windowRenderer, 0xFF, 0xFF , 0xFF, 0xFF);

    SDL_Rect srcRect = {0, 0, 640, 480};
    SDL_Rect dstRect = {0, 0, 200, 100};

    SDL_RenderCopy(windowRenderer,
                   texture.sdlTexture,
                   &texture.sourceRect,
                   &dstRect);

    SDL_RenderPresent(windowRenderer);

}

