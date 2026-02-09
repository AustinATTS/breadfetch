#include "info/cpu.h"
#include <fstream>

namespace breadfetch::cpu {

    std::string Model ( ) {
        std::ifstream cpuinfo("/proc/cpuinfo");
        std::string line;

        while (std::getline(cpuinfo, line)) {
            if (line.rfind("model name", 0) == 0) {
                return line.substr(line.find(":") + 2);
            }
        }
        return "unknown";
    }
} // namespace breadfetch::cpu
