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

#define F(x) std::string SystemInfo::x()

    F(GetUsername)     { return user::Name(); }
    F(GetHostname)     { return user::Hostname(); }
    F(GetLogin)        { return user::Login(); }

    F(GetOS)           { return os::PrettyName(); }
    F(GetKernel)       { return os::Kernel(); }
    F(GetArchitecture) { return os::Architecture(); }
    F(GetChassis)      { return os::Chassis(); }
    F(GetOSAge)        { return os::Age(); }

    F(GetCPU)          { return cpu::Model(); }
    F(GetGPU)          { return gfx::GPU(); }
    F(GetMemory)       { return memory::Usage(); }
    F(GetSwap)         { return memory::Swap(); }

    F(GetShell)        { return environment::Shell(); }
    F(GetTerminal)     { return environment::Terminal(); }
    F(GetTerminalFont) { return environment::TerminalFont(); }
    F(GetSession)      { return environment::Session(); }
    F(GetDisplay)      { return environment::Display(); }
    F(GetColours)      { return environment::Colours(); }

    F(GetInterface)    { return network::Interface(); }
    F(GetLocalIP)      { return network::LocalIP(); }

    F(GetPackages)     { return package::Count(); }
    F(GetGit)          { return "installed"; }

    F(GetUptime)       { return time::Uptime(); }
    F(GetDate)         { return time::Date(); }
    F(GetTime)         { return time::Clock(); }

#undef F

}
