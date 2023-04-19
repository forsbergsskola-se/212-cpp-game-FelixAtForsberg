#include <SDL.h>
#include <SDL_image.h>
#include "window.h"
#include "error.h"

using std::string;

// TODO: Rule of 3
//Window::Window(string title, unsigned int &posX, unsigned int &posY, const int &sizeW, const int &sizeH, SDL_WindowFlags &flags)

Window::Window(const string& title, int posX, int posY, const int sizeW, const int sizeH, SDL_WindowFlags flags) {

        SDLWindow = SDL_CreateWindow(title.c_str(),
                         posX, posY,
                         sizeW, sizeH,
                         flags);

        if (!SDLWindow)
            error::FatalErrorExit(string("Unable to create SDL Window"));

        Surface = SDL_GetWindowSurface(SDLWindow);

        SDLRenderer = SDL_CreateRenderer(SDLWindow, -1, SDL_RENDERER_ACCELERATED);

        int initResult = IMG_Init(IMG_INIT_PNG); // | IMG_INIT_JPG;

        if (initResult == 0)
            error::FatalErrorExit("Failed to initialize SDL2_image");
}

void Window::Update(){
    SDL_UpdateWindowSurface(this->SDLWindow);
}

Window::~Window() {
    SDL_DestroyWindow(SDLWindow);
}
