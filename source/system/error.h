#pragma once

#include <string>

class error {
public:
    static void FatalErrorExit(const std::string &errorMsg, int exitCode = 1);
};