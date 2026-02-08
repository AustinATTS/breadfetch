#include "system_info.h"
#include <fstream>
#include <sstream>
#include <cstring>
#include <unistd.h>
#include <sys/utsname.h>
#include <sys/sysinfo.h>
#include <pwd.h>

namespace breadfetch {

    std::string SystemInfo::GetHostname() {
        char hostname[256];
        if (gethostname(hostname, sizeof(hostname)) == 0) {
            return std::string(hostname);
        }
        return "unknown";
    }

    std::string SystemInfo::GetUsername() {
        struct passwd *pw = getpwuid(getuid());
        if (pw) {
            return std::string(pw->pw_name);
        }
        return "unknown";
    }

    std::string SystemInfo::GetOS() {
        std::ifstream osRelease("/etc/os-release");
        std::string line;
        std::string prettyName = "Linux";

        if (osRelease.is_open()) {
            while (std::getline(osRelease, line)) {
                if (line.find("PRETTY_NAME=") == 0) {
                    prettyName = line.substr(13);
                    // Remove quotes
                    if (prettyName.front() == '"') prettyName.erase(0, 1);
                    if (prettyName.back() == '"') prettyName.pop_back();
                    break;
                }
            }
            osRelease.close();
        }

        return prettyName;
    }

    std::string SystemInfo::GetKernel() {
        struct utsname buffer;
        if (uname(&buffer) == 0) {
            return std::string(buffer.release);
        }
        return "unknown";
    }

    std::string SystemInfo::GetUptime() {
        struct sysinfo info;
        if (sysinfo(&info) == 0) {
            long uptime = info.uptime;
            int days = uptime / 86400;
            int hours = (uptime % 86400) / 3600;
            int minutes = (uptime % 3600) / 60;

            std::stringstream ss;
            if (days > 0) {
                ss << days << "d ";
            }
            if (hours > 0 || days > 0) {
                ss << hours << "h ";
            }
            ss << minutes << "m";

            return ss.str();
        }
        return "unknown";
    }

    std::string SystemInfo::GetShell() {
        const char* shell = getenv("SHELL");
        if (shell) {
            std::string shellPath(shell);
            size_t pos = shellPath.find_last_of('/');
            if (pos != std::string::npos) {
                return shellPath.substr(pos + 1);
            }
            return shellPath;
        }
        return "unknown";
    }

    std::string SystemInfo::GetCPU() {
        std::ifstream cpuinfo("/proc/cpuinfo");
        std::string line;
        std::string cpuModel = "unknown";

        if (cpuinfo.is_open()) {
            while (std::getline(cpuinfo, line)) {
                if (line.find("model name") == 0) {
                    size_t pos = line.find(':');
                    if (pos != std::string::npos) {
                        cpuModel = line.substr(pos + 2);
                        break;
                    }
                }
            }
            cpuinfo.close();
        }

        return cpuModel;
    }

    std::string SystemInfo::GetMemory() {
        struct sysinfo info;
        if (sysinfo(&info) == 0) {
            unsigned long totalMB = info.totalram / 1024 / 1024;
            unsigned long usedMB = (info.totalram - info.freeram - info.bufferram - info.sharedram) / 1024 / 1024;

            std::stringstream ss;
            ss << usedMB << "MB / " << totalMB << "MB";
            return ss.str();
        }
        return "unknown";
    }

    std::string SystemInfo::GetArchitecture() {
        struct utsname buffer;
        if (uname(&buffer) == 0) {
            return std::string(buffer.machine);
        }
        return "unknown";
    }

} // namespace breadfetch