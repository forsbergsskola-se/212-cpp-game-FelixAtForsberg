#include <SDL.h>
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
}

void Window::Update(){
    SDL_UpdateWindowSurface(this->SDLWindow);
}

Window::~Window() {
    SDL_DestroyWindow(SDLWindow);
}
