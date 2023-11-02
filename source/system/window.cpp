#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL_video.h>

#include <iostream>
#include <string>
#include <cstdio>
#include <array>

#include "window.h"
#include "../graphics/texture.h"
#include "debug_log.h"

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
        DebugLog::LogWithSDLError( "Window could not be created!");
    }

    windowRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_SOFTWARE);
    if (windowRenderer == nullptr) {
        DebugLog::LogWithSDLError( "Could not create a renderer");
    }

    SDL_SetRenderDrawColor(windowRenderer, 0xff, 0xff , 0xff, 0xff);


    windowSurface = SDL_GetWindowSurface(sdlWindow);
    if (windowSurface == nullptr) {
        DebugLog::LogWithSDLError( "Could not retrieve window surface");
    }

//    windowFormat = SDL_GetWindowPixelFormat(sdlWindow);

//    Initialize renderer color
    SDL_SetRenderDrawColor( windowRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

}

Window::~Window()
{
    std::cout << "Window was destroyed";
	//Destroy window
	SDL_DestroyRenderer(windowRenderer );
	SDL_DestroyWindow( sdlWindow );
	sdlWindow = nullptr;
    windowRenderer = nullptr;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

//void Window::LoadImage(std::string &imagePath, SDL_PixelFormat format) {
//}

void Window::RenderTexture(Texture& texture) {

    SDL_RenderClear(windowRenderer);
    SDL_SetRenderDrawColor(windowRenderer, 0xff, 0xff , 0xff, 0xff);

    SDL_Rect srcRect = {0, 0, 100, 100};
    SDL_Rect dstRect = {0, 0, 100, 100};

    int result = SDL_RenderCopy(windowRenderer,
                   texture.sdlTexture,
                   &srcRect,
                   &dstRect);

}

void Window::LoadImage(std::string &imagePath)
{

    Texture newTexture = Texture(windowRenderer, imagePath);

//    LoadImage(imagePath, windowSurface->format);
}
