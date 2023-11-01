#pragma once

class Window {
    SDL_Window*   sdlWindow;
    SDL_Renderer* windowRenderer;
    SDL_Surface*  windowSurface;

public:
    Window();
    ~Window();
    void SetWindowImage(std::string& imagePath);
};
