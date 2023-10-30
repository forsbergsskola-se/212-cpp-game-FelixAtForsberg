#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <iostream>
#include <string>
#include <cstdio>
#include <format>
#include "window.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
//The window we'll be rendering to

//The window renderer


//Starts up SDL and creates window

Window::Window() {

    SDL_Init( SDL_INIT_VIDEO );


    if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
        printf("Warning: Linear texture filtering not enabled!");
    }

    sdlWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                                 SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (sdlWindow == nullptr) {
//        std::cout << std::format("Window could not be created! SDL Error: {}\n", SDL_GetError());
        return;
    }

    sdlSurface = SDL_GetWindowSurface(sdlWindow);

    sdlRenderer = SDL_CreateRenderer( sdlWindow, -1, SDL_RENDERER_ACCELERATED );
    if( sdlRenderer == nullptr )
    {
//        std::cout << std::format( "Renderer could not be created! SDL Error: {}\n", SDL_GetError() );
    }

    //Initialize renderer color
    SDL_SetRenderDrawColor( sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
//        std::cout << std::format( "SDL_image could not initialize! SDL_image Error: {}\n", IMG_GetError() );
    }

}

Window::~Window()
{

	//Destroy window
	SDL_DestroyRenderer( sdlRenderer );
	SDL_DestroyWindow( sdlWindow );
	sdlWindow = nullptr;
	sdlRenderer = nullptr;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void Window::LoadImageFromPath( const std::string& imagePath )
{
    SDL_Texture* newTexture;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load( imagePath.c_str() );
	if( loadedSurface == nullptr )
	{
		printf( "Unable to load image %s! SDL_image Error: %s\n", imagePath.c_str(), IMG_GetError() );
        return;
	}


    //Create texture from surface pixels
    newTexture = SDL_CreateTextureFromSurface( sdlRenderer, loadedSurface );
    if( newTexture == nullptr )
    {
        printf( "Unable to create texture from %s! SDL Error: %s\n", imagePath.c_str(), SDL_GetError() );
    }

    //Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );

    if( newTexture == nullptr )
	{
//		std::cout << std::format( "Failed to load texture image!\n" );
	}

    //Load PNG texture
    SDL_RenderClear(sdlRenderer);
    SDL_RenderCopy(sdlRenderer, newTexture, NULL, NULL);
    SDL_RenderPresent(sdlRenderer);


}
