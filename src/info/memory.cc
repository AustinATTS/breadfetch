#include "info/memory.h"
#include <sys/sysinfo.h>
#include <sstream>

namespace breadfetch::memory {

    std::string Usage ( ) {
        struct sysinfo i{};
        if (sysinfo(&i) != 0)
            return "unknown";

        auto total = i.totalram / 1024 / 1024;
        auto used  = (i.totalram - i.freeram) / 1024 / 1024;

        std::ostringstream o;
        o << used << "MB / " << total << "MB";
        return o.str();
    }

    std::string Swap ( ) {
        struct sysinfo i{};
        if (sysinfo(&i) != 0 || i.totalswap == 0)
            return "none";

        auto total = i.totalswap / 1024 / 1024;
        auto used  = (i.totalswap - i.freeswap) / 1024 / 1024;

        std::ostringstream o;
        o << used << "MB / " << total << "MB";
        return o.str();
    }

} // namespace breadfetch::memory
