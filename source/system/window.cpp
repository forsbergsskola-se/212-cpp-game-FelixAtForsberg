#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL_video.h>

#include <iostream>
#include <string>
#include <cstdio>

#include "window.h"
#include "../graphics/texture_factory.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
//The window we'll be rendering to

//The window renderer


//Starts up SDL and creates window

Window::Window() {

    SDL_Init( SDL_INIT_VIDEO );

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
    }



    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        printf("Warning: Linear texture filtering not enabled!");
    }

    sdlWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                 SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (sdlWindow == nullptr) {
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return;
    }

    windowRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);


    //Initialize renderer color
//    SDL_SetRenderDrawColor( windowRenderer, 0xFF, 0xFF, 0xFF, 0xFF );


}

Window::~Window()
{
	//Destroy window
	SDL_DestroyRenderer(windowRenderer );
	SDL_DestroyWindow( sdlWindow );
	sdlWindow = nullptr;
    windowRenderer = nullptr;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void Window::SetWindowImage(std::string& imagePath)
{
    assert(windowRenderer != nullptr);
    assert(windowSurface->format != nullptr);

    TextureFactory::renderer = windowRenderer;
    TextureFactory::format = windowSurface->format;

    SDL_Texture* newTexture = TextureFactory::CreateTexture(imagePath);

    SDL_RenderClear(windowRenderer);
    SDL_RenderCopy(windowRenderer, newTexture, NULL, NULL);
    SDL_RenderPresent(windowRenderer);
//  SDL_UpdateWindowSurface( sdlWindow );
}
