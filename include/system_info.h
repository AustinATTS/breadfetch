#pragma once
#define SYSTEM_INFO_HEADER

#include <string>

namespace breadfetch {
    class SystemInfo {
        public:
        static std::string GetHostname ( );
        static std::string GetUsername ( );
        static std::string GetOS ( );
        static std::string GetKernel ( );
        static std::string GetUptime ( );
        static std::string GetShell ( );
        static std::string GetCPU ( );
        static std::string GetMemory ( );
        static std::string GetArchitecture ( );
    };
}