#include "system_info.h"
#include "display.h"

int main ( ) {
    breadfetch::Display::PrintBanner();
    breadfetch::Display::PrintSeparator();

    std::string username = breadfetch::SystemInfo::GetUsername();
    std::string hostname = breadfetch::SystemInfo::GetHostname();
    std::string userHost = username + "@" + hostname;

    breadfetch::Display::PrintInfo("User@Host", userHost);
    breadfetch::Display::PrintInfo("OS", breadfetch::SystemInfo::GetOS());
    breadfetch::Display::PrintInfo("Kernel", breadfetch::SystemInfo::GetKernel());
    breadfetch::Display::PrintInfo("Uptime", breadfetch::SystemInfo::GetUptime());
    breadfetch::Display::PrintInfo("Shell", breadfetch::SystemInfo::GetShell());
    breadfetch::Display::PrintInfo("CPU", breadfetch::SystemInfo::GetCPU());
    breadfetch::Display::PrintInfo("Memory", breadfetch::SystemInfo::GetMemory());
    breadfetch::Display::PrintInfo("Architecture", breadfetch::SystemInfo::GetArchitecture());

    breadfetch::Display::PrintSeparator();

    return 0;
}