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
            static std::string GetArchitecture ( );
            static std::string GetChassis ( );
            static std::string GetOSAge ( );

            static std::string GetCPU ( );
            static std::string GetGPU ( );
            static std::string GetMemory ( );
            static std::string GetSwap ( );
            static std::string GetDisk ( );

            static std::string GetShell ( );
            static std::string GetTerminal ( );
            static std::string GetTerminalFont ( );
            static std::string GetSession ( );
            static std::string GetDisplay ( );
            static std::string GetColours ( );

            static std::string GetPackages ( );
            static std::string GetGit ( );

            static std::string GetInterface ( );
            static std::string GetLocalIP ( );

            static std::string GetUptime ( );
            static std::string GetLogin ( );
            static std::string GetDate ( );
            static std::string GetTime ( );
    };
}