#include "system_static.h"
#include "debug_log.hpp"
#include <filesystem>
#include <mach-o/dyld.h>
#include <climits>
#include <array>

//     const std::filesystem::path curWorkDir = std::filesystem::current_path();


using std::filesystem::path;

namespace SDLGame::System {

    path GetExecutablePath() {
        auto pathBuffer = std::array<char, PATH_MAX>();
        uint32_t bufferSize = PATH_MAX;
        const uint32_t result = _NSGetExecutablePath(pathBuffer.data(), &bufferSize);

        if (result != 0) {
            DebugLog::Error("GetResourceDirectory() Failed, _NSGetExecutablePath result was: ", result);
        }

        return {pathBuffer.data()};
    }

    path GetResourceDirectory() {

        return path(GetExecutablePath() / DIR_REL_RESOURCES);
    }


    bool IsFilenameOnly(const path &path) {
        return (path.has_filename() && !path.has_parent_path());
    }

    path AsAbsAssetPath(const std::filesystem::path &assetPath) {

//        if (IsFilenameOnly(filename)) {
            return path{GetResourceDirectory() / assetPath};
//        }

//        throw (std::invalid_argument(filename));

    }

    std::filesystem::path AsRelAssetPath(const path &assetPath) {

//        if (IsFilenameOnly(assetPath)) {
            return path{ DIR_REL_RESOURCES / assetPath };
//        }
//        throw(std::invalid_argument(assetPath));
    }

}