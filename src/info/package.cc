#include "info/package.h"
#include <filesystem>

namespace breadfetch::package {

    std::string Count() {
        namespace fs = std::filesystem;
        if (fs::exists("/var/lib/pacman/local"))
            return std::to_string(
                std::distance(fs::directory_iterator("/var/lib/pacman/local"),
                              fs::directory_iterator()));
        return "unknown";
    }

} // namespace breadfetch::package
