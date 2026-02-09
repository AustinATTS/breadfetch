#include "info/gfx.h"
#include <fstream>

namespace breadfetch::gfx {

    std::string GPU() {
        std::ifstream f("/sys/class/drm/card0/device/vendor");
        return f.good() ? "GPU detected" : "unknown";
    }

} // namespace breadfetch::gfx
