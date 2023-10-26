#include "error.h"
#include <iostream>
#include <SDL.h>

using std::cout, std::endl, std::string;

// prints the errorMsg message,along with SDL_GetError() and then exits
void error::FatalErrorExit(const string &errorMsg, int exitCode) {
    cout << "FATAL: "      << endl
         << errorMsg       << endl
         << SDL_GetError() << endl;

    exit(exitCode);
}

