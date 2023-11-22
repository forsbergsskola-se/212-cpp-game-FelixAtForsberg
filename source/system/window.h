#pragma once

#include "graphics/render_context.h"
#include "graphics/texture.h"

namespace SDLGame {

    class Window {
        SDL_Window*      sdlWindow;

    //    void LoadImage(std::string& imagePath, SDL_PixelFormat* format);

    public:
        Window();
        ~Window();

        std::shared_ptr<RenderContext> renderContext;
        Texture CreateTexture( const std::filesystem::path& imageName ) const;

        static constexpr int SCREEN_WIDTH = 880;
        static constexpr int SCREEN_HEIGHT = 550;

        // Texture CreateTexture(const std::filesystem::path& imageName) const;

        void RenderTexture(const Texture& texture) const;
    };
}