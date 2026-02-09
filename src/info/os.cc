#include "info/os.h"
#include <fstream>
#include <sys/utsname.h>

namespace breadfetch::os {

    std::string PrettyName ( ) {
        std::ifstream os_release("/etc/os-release");
        std::string line;
        while (std::getline(os_release, line)) {
            if (line.rfind("PRETTY_NAME=", 0) == 0)
                return line.substr(13, line.size() - 14);
        }
        return "Linux";
    }

    std::string Kernel ( ) {
        utsname u{};
        return uname(&u) == 0 ? u.release : "unknown";
    }

    std::string Architecture ( ) {
        utsname u{};
        return uname(&u) == 0 ? u.machine : "unknown";
    }

    std::string Chassis ( ) {
        std::ifstream chassis_type("/sys/class/dmi/id/chassis_type");
        std::string value;
        return (chassis_type >> value) ? value : "unknown";
    }

    std::string Age ( ) {
        std::ifstream syslog("/var/log/installer/syslog");
        return syslog.good() ? "installed" : "unknown";
    }

} // namespace breadfetch::os
