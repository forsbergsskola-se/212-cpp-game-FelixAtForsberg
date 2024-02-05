#include "game_entity_renderable.h"


// SDLGame::GameEntityRenderable::GameEntityRenderable( const std::filesystem::path& imagePath, const std::weak_ptr<RenderContext>& context )
// : texture( std::make_shared<Texture>( imagePath, context ) ) {
//     // this->texture = std::make_shared<Texture>( TexturePath(), context );
// }


SDLGame::GameEntityRenderable::GameEntityRenderable( const std::filesystem::path& imagePath, const std::weak_ptr<RenderContext>& context ) :
texture( std::make_shared<Texture>( imagePath, context ) ) {

}


// Copy texture to renderContext renderer
void SDLGame::GameEntityRenderable::RenderEntity() {
    // auto const windowRenderer = renderContext.sdl->renderer;

    if(const auto renderContext = this->texture->renderContext.lock()) {
        const auto renderer = renderContext->sdl.renderer;

        const PositionedRect targetRect = { pos, this->texture->size };

        // wrap SDL_Rect so it gets destroyed after RenderEntity call
        const std::unique_ptr<SDL_Rect> dstRect( new SDL_Rect( targetRect ) );

        // nativeRect could be using Dimensions cast but I'd have to verify assembly output
        //            to make sure it's equally as fast after going through the compiler
        SDL_RenderCopy( renderer,
                        this->texture->sdl.texture,
                        &this->texture->sdl.nativeRect,
                        dstRect.get() );

    } else {
        DebugLog::LogError( "[RenderEntity] UNABLE TO RENDER ENTITY: Entity failed to acquire texture renderContext lock!" );
    }
}


// std::filesystem::path SDLGame::GameEntityRenderable::TexturePath() const {
//
//     return {"images/Error.png"};
// }
