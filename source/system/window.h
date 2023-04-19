#pragma once
#include "SDL.h"
#include <string>

const int WINDOW_DEFAULT_HEIGHT = 480;
const int WINDOW_DEFAULT_WIDTH  = 640;

const SDL_WindowFlags WINDOW_DEFAULT_FLAGS = SDL_WINDOW_SHOWN;

class Window {
    SDL_Window*   SDLWindow    { nullptr };
    SDL_Renderer* SDLRenderer  { nullptr };

public:
    explicit Window(const std::string& title, int posX = SDL_WINDOWPOS_UNDEFINED, int posY = SDL_WINDOWPOS_UNDEFINED,
           int sizeW = WINDOW_DEFAULT_WIDTH, int sizeH = WINDOW_DEFAULT_HEIGHT,
           SDL_WindowFlags flags = WINDOW_DEFAULT_FLAGS);

    void Update();

    SDL_Surface* Surface { nullptr };

    virtual ~Window();
};