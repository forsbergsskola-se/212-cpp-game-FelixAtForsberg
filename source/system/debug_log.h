#pragma once
#include <iostream>

//  ostream: basic_ostream<char>
// wostream: basic_ostream<wchar_t>

class DebugLog {

public:

//    template<typename... TPrint>
//    static void LogFailure(TPrint... printArgs) {
//
//        ExpandArgsToStream()
//            std::cout << std::endl;
//    }

    template<typename... TPrint>
    static void Log(TPrint... printArgs) {

        for (auto const &printArg: {printArgs...}) {
                std::cout << printArg << ' ';
            }
        std::cout << std::endl;
    }

    template<typename... TPrint>
    static void LogWithSDLError(TPrint... printArgs) {
        Log(printArgs...);
        std::cout << "SDL Error: \n" << SDL_GetError() << std::endl;
    }
};
