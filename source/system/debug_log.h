#pragma once
#include <iostream>
#include <SDL.h>
//#include <SDL2/SDL.h>

using std::string, std::string_view;

//  ostream: basic_ostream<char>
// wostream: basic_ostream<wchar_t>
//https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

    namespace CON {
        static constexpr string_view RESET {"\033[0m"};
        static constexpr string_view FG_RED {"\033[31m"};
        static constexpr string_view BOLD {"\033[1m"};



        namespace SET {
            static constexpr void BOLD_FG_RED() {
                std::cout << FG_RED << BOLD;
            }

            static constexpr void RESET() {
                std::cout << CON::RESET;
            }

        }

    };


namespace SDLGame {
    class DebugLog {



    public:
/*
    template<typename... TPrint>
    static void Log(TPrint... printArgs) {

        for (auto const &printArg: {printArgs...}) {
                std::cout << printArg << ' ';
            }
        std::cout << std::endl;
    }
*/

    // "Perfect Forwarding" - thanks GPT4
    // It got rid of the loop, too.
    template<typename... TPrint>
    static void Log(TPrint&&... printArgs) {
        (std::cout << ... << printArgs) << std::endl;
    }

    template<typename... TPrint>
    static void LogError(TPrint&&... printArgs) {
        CON::SET::BOLD_FG_RED();
        (std::cout << ... << printArgs)  << std::endl;
        CON::SET::RESET();
    }


    template<typename... TPrint>
    static void LogWithSDLError(TPrint&&... printArgs) {
        Log(printArgs...);
        std::cout << "SDL Error: \n" << SDL_GetError() << std::endl;
    }
};

}



