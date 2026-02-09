#include "info/user.h"
#include <unistd.h>
#include <pwd.h>

namespace breadfetch::user {

    std::string Name ( ) {
        if (auto* passwd = getpwuid(getuid()))
            return passwd->pw_name;
        return "unknown";
    }

    std::string Hostname ( ) {
        char buffer[256];
        return gethostname(buffer, sizeof(buffer)) == 0 ? buffer : "unknown";
    }

    std::string Login ( ) {
        const char* login = getlogin();
        return login ? login : "unknown";
    }

} // namespace breadfetch::user
