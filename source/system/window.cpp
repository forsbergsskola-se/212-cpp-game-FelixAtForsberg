#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>
#include <SDL_video.h>

#include <iostream>
#include <array>

#include "window.h"
#include "../graphics/texture.h"
#include "debug_log.hpp"

using namespace SDLGame;

//Screen dimension constants

//constexpr SDL_WindowFlags INITIAL_WINDOW_FLAGS = SDL_WINDOW_INPUT_FOCUS;

constexpr std::array<uint8_t, 4> INITIAL_RENDERER_COLOR{255, 255, 255, 255};

Window::Window() {


    SDL_Init(SDL_INIT_VIDEO);

    //Initialize PNG loading
    if (constexpr int imgFlags = IMG_INIT_PNG; !(IMG_Init(imgFlags) & imgFlags))
        DebugLog::LogError("SDL_image could not initialize! SDL_image Error: ", IMG_GetError());

    if (TTF_Init() < 0)
        DebugLog::LogError("Could not initialize SDL_ttf, Error:", TTF_GetError());

    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
        DebugLog::LogError("Warning: Linear texture filtering not enabled!");


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

    SDL_Renderer* windowRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_SOFTWARE);
    if (windowRenderer == nullptr) {
        DebugLog::LogWithSDLError("Could not create a renderer");
    }

    SDL_Surface* windowSurface = SDL_GetWindowSurface(sdlWindow);
    if ( windowSurface == nullptr) {
        DebugLog::LogWithSDLError("Could not retrieve window surface");
    }

    renderContext = std::make_shared<RenderContext>(windowRenderer, windowSurface);


    SDL_SetRenderDrawColor(windowRenderer, 0x1b, 0x1b, 0x1b, 0xFF);
}

Window::~Window() {
    std::cout << "window was destroyed";
    //Destroy window
    SDL_DestroyWindow(sdlWindow);
    sdlWindow = nullptr;
    renderContext = nullptr;

    //Quit SDL subsystems
    IMG_Quit();
    SDL_Quit();
}

Texture Window::CreateTexture( const std::filesystem::path& imageName ) const {
    const Texture newTexture = Texture(renderContext->sdl->renderer, imageName);
    return newTexture;
}

void Window::RenderTexture(const Texture &texture) const {

    auto const windowRenderer = renderContext->sdl->renderer;

    SDL_RenderClear(windowRenderer);
    SDL_SetRenderDrawColor(windowRenderer, 0xFF, 0xFF, 0xFF, 0xFF);


    constexpr SDL_Rect dstRect = {0, 0, 200, 100};

    SDL_RenderCopy(windowRenderer,
                   texture.sdlTexture,
                   &texture.sdlRect,
                   &dstRect);

    SDL_RenderPresent(windowRenderer);

}

