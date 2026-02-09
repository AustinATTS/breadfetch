#include "info/time.h"
#include <sys/sysinfo.h>
#include <ctime>
#include <sstream>

namespace breadfetch::time {

    std::string Uptime ( ) {
        struct sysinfo i{};
        sysinfo(&i);

        long s = i.uptime;
        int d = s / 86400;
        int h = (s % 86400) / 3600;
        int m = (s % 3600) / 60;

        std::ostringstream o;
        if (d) o << d << "d ";
        if (h) o << h << "h ";
        o << m << "m";
        return o.str();
    }

    std::string Date ( ) {
        std::time_t t = std::time(nullptr);
        char buffer[32];
        std::strftime(buffer, sizeof(buffer), "%d.%m.%Y", std::localtime(&t));
        return buffer;
    }

    std::string Clock ( ) {
        std::time_t t = std::time(nullptr);
        char buffer[32];
        std::strftime(buffer, sizeof(buffer), "%H:%M:%S", std::localtime(&t));
        return buffer;
    }

} // namespace breadfetch::time
