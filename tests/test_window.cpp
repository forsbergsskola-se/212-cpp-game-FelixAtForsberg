#include "gtest/gtest.h"
#include "system/window.h"
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
//#include "Window.h"

using namespace SDLGame;

class WindowTest : public ::testing::Test {
protected:
    Window* window;

    void SetUp() override {
        window = new Window();
    }

    void TearDown() override {
        delete window;
    }
};

