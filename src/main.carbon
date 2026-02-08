package BreadFetch api;

import Cpp library "system_info.h";
import Cpp library "display.h";

fn Main ( ) -> i32 {
    Cpp.breadfetch.Display.PrintBanner();
    Cpp.breadfetch.Display.PrintSeparator();

    var username: auto = Cpp.breadfetch.SystemInfo.GetUsername();
    var hostname: auto = Cpp.breadfetch.SystemInfo.GetHostname();
    var userHost: String = username + "@" + hostname;

    Cpp.breadfetch.Display.PrintInfo("User@Host", userHost);
    Cpp.breadfetch.Display.PrintInfo("OS", Cpp.breadfetch.SystemInfo.GetOS());
    Cpp.breadfetch.Display.PrintInfo("Kernel", Cpp.breadfetch.SystemInfo.GetKernel());
    Cpp.breadfetch.Display.PrintInfo("Uptime", Cpp.breadfetch.SystemInfo.GetUptime());
    Cpp.breadfetch.Display.PrintInfo("Shell", Cpp.breadfetch.SystemInfo.GetShell());
    Cpp.breadfetch.Display.PrintInfo("CPU", Cpp.breadfetch.SystemInfo.GetCPU());
    Cpp.breadfetch.Display.PrintInfo("Memory", Cpp.breadfetch.SystemInfo.GetMemory());
    Cpp.breadfetch.Display.PrintInfo("Architecture", Cpp.breadfetch.SystemInfo.GetArchitecture());

    Cpp.breadfetch.Display.PrintSeparator();

    return 0;
}