#include <SDL.h>
#include <SDL_image.h>
#include <cstdio>
#include <string>

#include "system/error.h"
#include "system/window.h"
#include "game/TextureFactory.h"

using std::string;

int main(int argc, char *argv[]) {

    if (SDL_Init(SDL_INIT_VIDEO) != 0)
        error::FatalErrorExit(string("Unable to initialize video subsystem"));

    Window window{ string{"SDL Tutorial"}};

    TextureFactory::Renderer = window.SDLRenderer; // Todo: read up on how many renderers are required
    TextureFactory::Format   = window.Surface->format;

    string imgPath = string{"../assets/chest.png"};
    SDL_Texture* texture = TextureFactory::CreateTexture(imgPath);

    SDL_Rect texture_rect;
    texture_rect.x = 0;  //the x coordinate
    texture_rect.y = 0; // the y coordinate
    texture_rect.w = 50; //the width of the texture
    texture_rect.h = 50; //the height of the texture

    SDL_Event e;
    bool quit = false;
    while (quit == false) {

    SDL_FillRect(window.Surface, nullptr, SDL_MapRGB(window.Surface->format, 0xFF, 0xFF, 0xFF));
    SDL_RenderClear(window.SDLRenderer);
    SDL_RenderCopy(window.SDLRenderer, texture, NULL, &texture_rect);
    SDL_RenderPresent(window.SDLRenderer);
//    window.Update();

    while (SDL_PollEvent(&e)) { if (e.type == SDL_QUIT) quit = true; }
    }

    //Quit SDL subsystems
    SDL_Quit();

    return 0;
}