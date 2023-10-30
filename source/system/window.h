#pragma once

class Window {
    SDL_Window* sdlWindow;
    SDL_Renderer* sdlRenderer;
    SDL_Surface* sdlSurface;

public:
    Window();
    ~Window();
    void LoadImageFromPath(const std::string& imagePath);
};
