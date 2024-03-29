#pragma once

#include "graphics/render_context.hpp"
#include "graphics/texture.h"


namespace SDLGame {
    class Window {
        SDL_Window* sdlWindow;

        //    void LoadImage(std::string& imagePath, SDL_PixelFormat* format);

    public:
        // Window();


        Window( const int& width, const int& height );


        ~Window();

        std::shared_ptr<RenderContext> renderContext;

        // Texture CreateTexture( const std::filesystem::path& imageName ) const;

        // Texture CreateTexture(const std::filesystem::path& imageName) const;

        // void RenderTexture( const Texture& texture );
    };
}
