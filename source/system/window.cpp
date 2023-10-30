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
        std::cout << "Window could not be created! SDL Error: " << SDL_GetError() << std::endl;
        return;
    }

    sdlSurface = SDL_GetWindowSurface(sdlWindow);

    //Initialize renderer color
    //SDL_SetRenderDrawColor( sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

    //Initialize PNG loading
    int imgFlags = IMG_INIT_PNG;
    if( !( IMG_Init( imgFlags ) & imgFlags ) )
    {
        std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
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

    //Convert surface to screen format
    SDL_Surface* optimizedSurface = SDL_ConvertSurface( loadedSurface, sdlSurface->format, 0 );
    if( optimizedSurface == NULL )
    {
        printf( "Unable to load image %s! SDL_image Error: %s\n", imagePath.c_str(), IMG_GetError() );
        return;
    }
    SDL_BlitSurface( optimizedSurface, NULL, sdlSurface, NULL );
    //Get rid of old loaded surface
    SDL_FreeSurface( loadedSurface );
    SDL_UpdateWindowSurface( sdlWindow );
}
