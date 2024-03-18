#include "game/game_ui.h"

#include "game/game.h"
#include "system/debug_log.hpp"
#include "system/system_static.h"
#include "system/file/file.h"



namespace SDLGame {

    // ----- UIManager -----

    UIManager::UIManager( const std::weak_ptr<RenderContext>& renderContext ) : renderContext( renderContext ) {}


    LabelHandle UIManager::AddPersistentLabel() {

        using namespace std::string_literals;

        const auto fontFile = System::File { System::AsRelAssetPath( "fonts/Roboto_Mono/static/RobotoMono-Regular.ttf" ) };

        if(!fontFile.exists)
            DebugLog::Error( "ERROR! Unable to find font: ", fontFile.path );

        const auto font = Font { fontFile.path.generic_string(), 16 };

        const auto& label = persistentLabels.emplace_back( std::make_unique<Label>( "Test"s, font, renderContext ) );

        const LabelHandle handle { *this, *label }; // construct handle from references

        return handle;
    }


    void UIManager::Render() const {
        uint labelVerticalOffset = 0;

        // Render the only thing UIManager currently supports
        for(const auto& element : persistentLabels) {

            constexpr int verticalPadding = -4;
            constexpr int horizontalMargin = 4;

            element->RenderTo( renderContext );

            element->renderOffset.x = horizontalMargin;
            element->renderOffset.y = labelVerticalOffset;
            labelVerticalOffset += element->bounds().size.h + verticalPadding;
        }

    }


    // --------- Label ---------

    // Could forego renderContext if we don't update the texture upon creation
    // Label could also perhaps just store a reference to the renderContext
    Label::Label( const std::string& text, const Font& font, const std::weak_ptr<RenderContext>& ctx )
    : font { font },
      text { text }
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

            const SDL_Rect& src  = this->sdlLabel.rect;
            const SDL_Rect  dest {
                this->sdlLabel.rect.x + renderOffset.x, this->sdlLabel.rect.y + renderOffset.y,
                this->sdlLabel.rect.w, this->sdlLabel.rect.h };


            SDL_RenderCopy( renderer, this->sdlLabel.texture.get(), &src, &dest );
        } else {
            DebugLog::Error( __func__, " failed to acquire renderContext lock!" );
        }
    }


    Bounds Label::bounds() const {
        return Bounds {sdlLabel.rect};
    }


    void LabelHandle::SetText( const std::string& newText ) const {
        if (label.text == newText) return; // texture's text is already correct
        label.text = newText;
        label.UpdateTexture( uiManager.renderContext );
    }


    // SDL_BlitSurface(textSurface, NULL, renderContext.lock()->sdl.surface, &destRect);





    // template <Printable TKey, Printable TValue>
    // void LabelKeyValue<TKey, TValue>::RenderTo( const std::weak_ptr<RenderContext>& renderContext ) {

    // Label::RenderTo()
    // }


}
