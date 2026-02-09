// A system fetch tool
// C++ implementation (Carbon interop version in main.carbon)

#include "system_info.h"
#include "display.h"

int main() {
    using breadfetch::Display;
    using breadfetch::SystemInfo;

    Display::PrintBanner();
    Display::PrintSeparator();

    // Identity
    const std::string userHost =
        SystemInfo::GetUsername() + "@" + SystemInfo::GetHostname();

    Display::PrintInfo("User@Host", userHost);
    Display::PrintInfo("Login",        SystemInfo::GetLogin());
    Display::PrintInfo("Shell",        SystemInfo::GetShell());
    Display::PrintInfo("Terminal",     SystemInfo::GetTerminal());
    Display::PrintInfo("Session",      SystemInfo::GetSession());
    Display::PrintInfo("Display",      SystemInfo::GetDisplay());

    Display::PrintSeparator();

    // Operating system
    Display::PrintInfo("OS",            SystemInfo::GetOS());
    Display::PrintInfo("Kernel",        SystemInfo::GetKernel());
    Display::PrintInfo("Architecture", SystemInfo::GetArchitecture());
    Display::PrintInfo("Chassis",       SystemInfo::GetChassis());
    Display::PrintInfo("OS Age",        SystemInfo::GetOSAge());

    Display::PrintSeparator();

    // Hardware
    Display::PrintInfo("CPU",           SystemInfo::GetCPU());
    Display::PrintInfo("GPU",           SystemInfo::GetGPU());
    Display::PrintInfo("Memory",        SystemInfo::GetMemory());
    Display::PrintInfo("Swap",          SystemInfo::GetSwap());

    Display::PrintSeparator();

    // Environment / software
    Display::PrintInfo("Packages",      SystemInfo::GetPackages());
    Display::PrintInfo("Git",           SystemInfo::GetGit());
    Display::PrintInfo("Colours",       SystemInfo::GetColours());

    Display::PrintSeparator();

    // Network
    Display::PrintInfo("Interface",     SystemInfo::GetInterface());
    Display::PrintInfo("Local IP",      SystemInfo::GetLocalIP());

    Display::PrintSeparator();

    // Time
    Display::PrintInfo("Uptime",         SystemInfo::GetUptime());
    Display::PrintInfo("Date",           SystemInfo::GetDate());
    Display::PrintInfo("Time",           SystemInfo::GetTime());

    Display::PrintSeparator();
    return 0;
}
