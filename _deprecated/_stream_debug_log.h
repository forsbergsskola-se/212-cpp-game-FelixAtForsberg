#pragma once
#include <iostream>

//  ostream: basic_ostream<char>
// wostream: basic_ostream<wchar_t>

class DebugLog {


    template<typename TStreamChar, typename... TPrint>
    static auto ExpandArgsToStream(TPrint&... printArgs) -> std::basic_ostream<TStreamChar>
    {
        std::basic_ostream<TStreamChar> stream; // unpack arguments to array
        for (auto const &printArg: {printArgs...}) {
                stream << printArg;
                std::cout << ' ';
            }
        return stream;
    }

    template<typename... TPrint>
    static std::ostream ExpandArgsToStream(TPrint&... printArgs) {
        return ExpandArgsToOstream<char>(printArgs...);
    }

public:

//    template<typename... TPrint>
//    static void LogFailure(TPrint... printArgs) {
//
//        ExpandArgsToStream()
//            std::cout << std::endl;
//    }

    template<typename... TPrint>
    static void Log(TPrint&... printArgs) {
        std::cout << ExpandArgsToStream(printArgs...) << std::endl;
    }

    template<typename... TPrint>
    static void LogWithSDLError(TPrint&... printArgs) {
        std::cout << ExpandArgsToStream(printArgs...) << "\n" << SDL_GetError() << std::endl;

    }
};
