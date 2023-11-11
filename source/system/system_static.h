#pragma once

#include <filesystem>

namespace SDLGame::System {

    constexpr std::string_view DIR_REL_RESOURCES = "Resources/";

    std::filesystem::path GetExecutablePath();

    bool IsFilenameOnly(const std::filesystem::path& path);

    // Just prepends asset path or throws if not a filename
    std::filesystem::path AsAbsAssetPath(const std::filesystem::path& assetPath);
    std::filesystem::path AsRelAssetPath(const std::filesystem::path& assetPath);
}