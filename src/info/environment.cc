#include "info/environment.h"
#include <cstdlib>

namespace breadfetch::environment {

    std::string Shell ( ) {
        return getenv("SHELL") ?: "unknown";
    }

    std::string Terminal ( ) {
        return getenv("TERM") ?: "unknown";
    }

    std::string Session ( ) {
        return getenv("XDG_SESSION_TYPE") ?: "unknown";
    }

    std::string Display ( ) {
        return getenv("DISPLAY") ?: getenv("WAYLAND_DISPLAY") ?: "none";
    }

    std::string Colours ( ) {
        return getenv("COLORTERM") ?: "unknown";
    }

    std::string TerminalFont ( ) {
        return "unknown";
    }

} // namespace breadfetch::environment
