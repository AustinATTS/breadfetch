#include "info/memory.h"
#include <sys/sysinfo.h>
#include <sstream>
#include <iomanip>

namespace breadfetch::memory {

    static double UnitDivisor (const std::string& unit, std::string& label) {
        if (unit == "B") {
            return 1.0;
        }
        if (unit == "KB") {
            return 1024.0;
        }
        if (unit == "MB") {
            return 1024.0 * 1024.0;
        }
        if (unit == "GB") {
            return 1024.0 * 1024.0 * 1024.0;
        }
        if (unit == "TB") {
            return 1024.0 * 1024.0 * 1024.0 * 1024.0;
        }

        // Default fallback
        label = "MB";
        return 1024.0 * 1024.0;
    }

    static std::string FormatUsage (unsigned long long usedBytes, unsigned long long totalBytes, const std::string& unit) {
        std::string label = unit;
        double divisor = UnitDivisor(unit, label);

        double used  = static_cast<double>(usedBytes)  / divisor;
        double total = static_cast<double>(totalBytes) / divisor;

        std::ostringstream ss;
        ss << std::fixed << std::setprecision(1)
           << used << " " << label << " / "
           << total << " " << label;

        return ss.str();
    }

    std::string Usage (const std::string& unit) {
        struct sysinfo info{};
        if (sysinfo(&info) != 0) {
            return "unknown";
        }

        const unsigned long long scale = info.mem_unit;

        unsigned long long total = static_cast<unsigned long long>(info.totalram) * scale;

        unsigned long long free = static_cast<unsigned long long>(info.freeram) * scale;

        unsigned long long buffers = static_cast<unsigned long long>(info.bufferram) * scale;

        unsigned long long used = total - free - buffers;

        return FormatUsage(used, total, unit);
    }

    std::string Swap (const std::string& unit) {
        struct sysinfo info{};
        if (sysinfo(&info) != 0) {
            return "unknown";
        }

        const unsigned long long scale = info.mem_unit;

        unsigned long long total = static_cast<unsigned long long>(info.totalswap) * scale;

        if (total == 0) {
            return "0 / 0";
        }

        unsigned long long free = static_cast<unsigned long long>(info.freeswap) * scale;

        unsigned long long used = total - free;

        return FormatUsage(used, total, unit);
    }

} // namespace breadfetch::memory
