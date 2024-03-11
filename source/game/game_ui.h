#pragma once
#include <filesystem>
#include <SDL_ttf.h>
#include <string>
#include <vector>

#include "graphics/render_context.hpp"
#include "system/sdl_cpp_interop.hpp"

namespace SDLGame {
    struct Label;

    template <typename T>
    concept Printable = requires( T a, std::ostream& os ) {
        { os << a } -> std::convertible_to<std::ostream&>;
    };



    struct UIManager {

        // public:
        explicit UIManager( const std::weak_ptr<RenderContext>& renderContext );


        void Render() const;


        const std::weak_ptr<RenderContext> renderContext;

        // template <Printable T>
        // void AddPersistentStatusLabel(T ref);

        void AddPersistentLabel();


        std::vector<std::unique_ptr<Label>> persistentLabels;
        // std::vector< std::unique_ptr<UIElement>> elements;
    };


    // ======= UIElement (Base) =======


    struct UIElement {
        virtual ~UIElement() = default;


        virtual void RenderTo( const std::weak_ptr<RenderContext>& renderContext ) = 0;
    };


    // ======= Font Class =======
    // (wraps SDL)

    struct Font {
        const std::filesystem::path path;
        const int size;


        Font( const std::filesystem::path& path, const int size )
        : path { path },
          size { size },
          sdlFont { SDLFont { path.c_str(), size } } {}


        const struct SDLFont {
            explicit SDLFont( const char* path, const int ptsize )
            : font { TTF_OpenFont( path, ptsize ) } {}


            TTF_Font* font;

        } sdlFont;
    };

    // ======= Label <- UIElement =======

    // template <Printable TKey, Printable TValue>
    // struct LabelKeyValue<TKey, TValue> final : UIElement {

    // TKey key;
    // TValue value;
    struct Label final : UIElement {

        explicit Label( const std::string& text, const Font& font, const std::weak_ptr<RenderContext>& ctx );

        std::string text;

        const Font font;

        // Must be called if text changes
        // There could be better soltuions, see problem ID 3eb9bf17-0e72-463c-b961-c491236c3179
        void UpdateTexture( const std::weak_ptr<RenderContext>& renderContext );

        void RenderTo( const std::weak_ptr<RenderContext>& renderContext ) override;

        // cached texture required for SDL text drawing,
        // with rect copied from temporary surface gotten from TTF_RenderUTF8
        struct SDLLabel {
            SDLLabel() :
                texture{ nullptr },
                rect{ 0,0,0,0 } {
            }




            // elememt_type, deleter_type
            // decltype(&SDL_FreeSurface) = void (*)(SDL_Surface*)  --- type/signature of deleter function
            // std::unique_ptr<SDL_Surface, decltype(&SDL_FreeSurface)> surface;    // cached surface we draw text to
            // std::unique_ptr<SDL_Texture, decltype(&SDL_DestroyTexture)> texture; // texture we create from cached surface

            // std::unique_ptr<SDL_Surface, SDLSurfaceDeleter> surface; // cached surface we draw text to

            std::unique_ptr<SDL_Texture, SDLTextureDeleter> texture; // texture we create from cached surface
            SDL_Rect rect;

        } sdlLabel;

    };



}
