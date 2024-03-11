#include "game/game_ui.h"

#include "system/debug_log.hpp"
#include "system/system_static.h"
#include "system/file/file.h"



namespace SDLGame {

    // ----- UIManager -----

    UIManager::UIManager( const std::weak_ptr<RenderContext>& renderContext ) : renderContext( renderContext ) {}


    void UIManager::AddPersistentLabel() {

        using namespace std::string_literals;


        const auto fontFile = System::File { System::AsRelAssetPath( "fonts/Roboto_Mono/static/RobotoMono-Regular.ttf" ) };

        if(!fontFile.exists)
            DebugLog::Error( "ERROR! Unable to find font: ", fontFile.path );

        auto font = Font { fontFile.path.generic_string(), 72 };

        persistentLabels.emplace_back( std::make_unique<Label>( "Test"s, font, renderContext ) );
    }


    void UIManager::Render() const {
        for(const auto& element : persistentLabels)
            element->RenderTo( renderContext );
    }


    // --------- Label ---------

    // Could forego renderContext if we don't update the texture upon creation
    Label::Label( const std::string& text, const Font& font, const std::weak_ptr<RenderContext>& ctx )
    : text { text },
      font { font }
    {
        UpdateTexture( ctx );
    }


    // : surface(SDL_CreateRGBSurface(0, 100, 100, 32, 0, 0, 0, 0)),
    // texture(SDL_CreateTexture(renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STATIC, 100, 100)) {}

    // Render text to SDLLabel Surface, from surface: set SDLLabel.rect, then create texture from surface
    void Label::UpdateTexture( const std::weak_ptr<RenderContext>& renderContext ) {

        constexpr SDL_Color color = { 0, 0, 0 };

        if(const auto ctx = renderContext.lock()) {

            SDL_Surface* textSurface = TTF_RenderUTF8_Blended( font.sdlFont.font, this->text.c_str(), color );

            this->sdlLabel.rect = textSurface->clip_rect;

            SDL_Renderer* renderer = ctx->sdl.renderer;
            SDL_Texture* textTexture = SDL_CreateTextureFromSurface( renderer, textSurface ); // If too slow: implement streaming texture

            this->sdlLabel.texture.reset( textTexture );
        } else {
            DebugLog::Error( __func__, " failed to acquire renderContext lock!" );
        }
    }

    void Label::RenderTo( const std::weak_ptr<RenderContext>& renderContext ) {
        if(const auto ctx = renderContext.lock()) {

            SDL_Renderer* renderer = ctx->sdl.renderer;

            const SDL_Rect src  = this->sdlLabel.rect;
            const SDL_Rect dest = this->sdlLabel.rect;

            SDL_RenderCopy( renderer, this->sdlLabel.texture.get(), &src, &dest );
        } else {
            DebugLog::Error( __func__, " failed to acquire renderContext lock!" );
        }
    }


        // SDL_BlitSurface(textSurface, NULL, renderContext.lock()->sdl.surface, &destRect);





    // template <Printable TKey, Printable TValue>
    // void LabelKeyValue<TKey, TValue>::RenderTo( const std::weak_ptr<RenderContext>& renderContext ) {

    // Label::RenderTo()
    // }


}
