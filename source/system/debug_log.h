#pragma once

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <SDL.h>
//#include <SDL2/SDL.h>

using std::string_view;

//  ostream: basic_ostream<char>
// wostream: basic_ostream<wchar_t>
//https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

namespace CON {

    static const std::string ESC{"\033["};

    static std::unordered_map<std::string, std::string> FG =
    {
        {"RED",   "31m"},
        {"GREEN", "32m"},
    };

    static std::unordered_map<std::string, std::string> TEXT =
    {
        {"RESET",   "0m"},
        {"BOLD",    "1m"},
    };

    static std::string SET(const std::string& SEQ) {
        std::stringstream ss;
        ss << ESC << SEQ;
        return ss.str();
    }

};

using namespace CON;

namespace SDLGame {
    struct DebugLog {

        template<typename... TPrint>
        static void Log(TPrint&&... printArgs) {
            (std::cout << ... << printArgs) << std::endl;
        }

        template<typename... TPrint>
        static void LogEscPrefix(std::string prefix, TPrint&&... printArgs) {
            std::cout << SET(prefix);
            Log(printArgs...);
            std::cout << SET(TEXT["RESET"]);

        }

        template<typename... TPrint>
        static void LogSuccess(TPrint&&... printArgs) {
            LogEscPrefix(FG["GREEN"], printArgs...);
        }


        template<typename... TPrint>
        static void LogError(TPrint&&... printArgs) {
            std::cout << SET( FG["RED"]);
            (std::cout << ... << printArgs) << std::endl;
            std::cout << SET(TEXT["RESET"]);
        }


        template<typename... TPrint>
        static void LogWithSDLError(TPrint&&... printArgs) {
            Log(printArgs...);
            std::cout << "SDL Error: \n" << SDL_GetError() << std::endl;
        }
    };

}



