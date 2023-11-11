#pragma once

#include "../graphics/texture.h"

namespace SDLGame {

    class Window {
        SDL_Window*      sdlWindow;
        SDL_Renderer*    windowRenderer;
        SDL_Surface*     windowSurface;
        SDL_PixelFormat* windowFormat;

    //    void LoadImage(std::string& imagePath, SDL_PixelFormat* format);

    public:
        Window();
        ~Window();

        static constexpr int SCREEN_WIDTH = 640;
        static constexpr int SCREEN_HEIGHT = 480;

        Texture CreateTexture(const std::filesystem::path& imagePath);

        void RenderTexture(const Texture& texture);
    };
}