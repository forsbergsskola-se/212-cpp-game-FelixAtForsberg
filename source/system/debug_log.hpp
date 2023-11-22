#pragma once

#include <iostream>
#include <sstream>
#include <unordered_map>
#include <SDL.h>
//#include <SDL2/SDL.h>

#define __STORE_CTOR_LINE__ constexpr unsigned int _ctor_start = (__LINE__);
#define __CTOR_LINE__ (__LINE__ - _ctor_start)

using std::string_view;

//  ostream: basic_ostream<char>
// wostream: basic_ostream<wchar_t>
//https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797

namespace CON {

    static const std::string ESC{"\033["};

    static std::unordered_map<std::string, std::string> FG =
    {
        {"RED",     "31m"},
        {"GREEN",   "32m"},
        {"YELLOW",  "33m"},
        {"BLUE",    "34m"},
        {"MAGENTA", "35m"},
        {"CYAN",    "36m"},
        {"WHITE",   "37m"},
        {"DEFAULT", "39m"},
    };

    static std::unordered_map<std::string, std::string> FGB =
    {
        {"BLACK",   "90m"},
        {"RED",     "91m"},
        {"GREEN",   "92m"},
        {"YELLOW",  "93m"},
        {"BLUE",    "94m"},
        {"MAGENTA", "95m"},
        {"CYAN",    "96m"},
        {"WHITE",   "97m"},
    };

    static std::unordered_map<std::string, std::string> TXT =
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

    private:
        template<typename... TPrint>
        static void Pipe(std::ostream& stream, TPrint&&... printArgs) {
            (stream << ... << printArgs) << std::endl;
        }

        template<typename... TPrint>
        static void PipeWithEscPrefix(std::ostream& stream, std::string prefix, TPrint&&... printArgs) {
            stream << SET(prefix);
            Pipe(stream, printArgs...);
            stream << SET(TXT["RESET"]);
        }

    public:

        template<typename... TPrint>
        static void Log(TPrint&&... printArgs) {
            Pipe(std::cout, printArgs...);
        }

        template<typename... TPrint>
        static void Error(TPrint&&... printArgs) {
            Pipe(std::cerr, printArgs...);
        }




        // Neutral + Good Logs

        template<typename... TPrint>
        static void LogSuccess(TPrint&&... printArgs) {
            PipeWithEscPrefix(std::cout, FG["GREEN"], printArgs...);
        }

        template<typename... TPrint>
        static void LogCyan(TPrint&&... printArgs) {
            PipeWithEscPrefix(std::cout, FGB["CYAN"], printArgs...);
        }

        // "Bad" Logs

        template<typename... TPrint>
        static void LogWarn(TPrint&&... printArgs) {
            PipeWithEscPrefix(std::cerr, FG["YELLOW"], printArgs...);
        }

        template<typename... TPrint>
        static void LogError(TPrint&&... printArgs) {
            PipeWithEscPrefix(std::cerr, FG["RED"], printArgs...);
        }

        template<typename... TPrint>
        static void LogWithSDLError(TPrint&&... printArgs) {
            Error(printArgs...);
            std::cerr << "SDL Error: \n" << SDL_GetError() << std::endl;
        }

    };

}



