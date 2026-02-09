#pragma once
#include <string>

namespace breadfetch::memory {
    static double UnitDivisor (const std::string& unit, std::string& label);
    static std::string FormatUsage (unsigned long long usedBytes, unsigned long long totalBytes, const std::string& unit);
    std::string Usage (const std::string& unit);
    std::string Swap (const std::string& unit);
} // namespace breadfetch::memory