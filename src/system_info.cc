#include "system_info.h"

#include "info/user.h"
#include "info/os.h"
#include "info/cpu.h"
#include "info/memory.h"
#include "info/time.h"
#include "info/environment.h"
#include "info/network.h"
#include "info/gfx.h"
#include "info/package.h"

namespace breadfetch {

    std::string SystemInfo::GetUsername ( ) {
        return user::Name();
    }
    std::string SystemInfo::GetHostname ( ) {
        return user::Hostname();
    }
    std::string SystemInfo::GetLogin ( ) {
        return user::Login();
    }

    std::string SystemInfo::GetOS ( ) {
        return os::PrettyName();
    }
    std::string SystemInfo::GetKernel ( ) {
        return os::Kernel();
    }
    std::string SystemInfo::GetArchitecture ( ) {
        return os::Architecture();
    }
    std::string SystemInfo::GetChassis ( ) {
        return os::Chassis();
    }
    std::string SystemInfo::GetOSAge ( ) {
        return os::Age();
    }

    std::string SystemInfo::GetCPU ( ) {
        return cpu::Model();
    }
    std::string SystemInfo::GetGPU ( ) {
        return gfx::GPU();
    }
    std::string SystemInfo::GetMemory (const std::string& unit) {
        return memory::Usage(unit);
    }
    std::string SystemInfo::GetSwap (const std::string& unit) {
        return memory::Swap(unit);
    }

    std::string SystemInfo::GetShell ( ) {
        return environment::Shell();
    }
    std::string SystemInfo::GetTerminal ( ) {
        return environment::Terminal();
    }
    std::string SystemInfo::GetTerminalFont ( ) {
        return environment::TerminalFont();
    }
    std::string SystemInfo::GetSession ( ) {
        return environment::Session();
    }
    std::string SystemInfo::GetDisplay ( ) {
        return environment::Display();
    }
    std::string SystemInfo::GetColours ( ) {
        return environment::Colours();
    }

    std::string SystemInfo::GetInterface ( ) {
        return network::Interface();
    }
    std::string SystemInfo::GetLocalIP ( ) {
        return network::LocalIP();
    }

    std::string SystemInfo::GetPackages ( ) {
        return package::Count();
    }
    std::string SystemInfo::GetGit ( ) {
        return "installed";
    }

    std::string SystemInfo::GetUptime ( ) {
        return time::Uptime();
    }
    std::string SystemInfo::GetDate ( ) {
        return time::Date();
    }
    std::string SystemInfo::GetTime ( ) {
        return time::Clock();
    }


} // namespace::breadfetch
