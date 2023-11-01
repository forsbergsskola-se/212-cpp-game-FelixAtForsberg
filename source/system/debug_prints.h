#pragma once

#define CON_ESC         0x1B
#define CON_SEP         0x3B
#define CON_STYLE_RESET 0x6D
#define CON_COL_FG_RED  0x33316D

#include <iostream>
class DebugLog {
public:

    template <typename... TPrintArgs>
    static void LogFailure(TPrintArgs... printArgs);
};

template<typename... TPrint>
void DebugLog::LogFailure(TPrint... printArgs) {

    for (auto const& printArg : {printArgs...}) {
        std::cout << printArg;
        std::cout << ' ' << std::flush;
    }
    std::cout << std::endl;


}
