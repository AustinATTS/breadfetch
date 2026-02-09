// breadfetch - A system fetch tool
// C++ implementation (Carbon interop version in main.carbon)

#include "system_info.h"
#include "display.h"
#include "config.h"
#include <iostream>
#include <fstream>

int main(int argument_count, char* argument_vector[]) {
    using breadfetch::Display;
    using breadfetch::SystemInfo;
    using breadfetch::Config;

    // Load configuration
    Config config;
    std::string configPath = Config::GetDefaultConfigPath();

    // Create default config if missing
    std::ifstream testFile(configPath);
    if (!testFile.good()) {
        std::cout << "Creating default config at: " << configPath << std::endl;
        Config::CreateDefaultConfig(configPath);
    }
    testFile.close();

    if (!config.LoadFromFile(configPath)) {
        std::cerr << "Warning: Failed to load config, using defaults" << std::endl;
    }

    // Header
    Display::PrintBanner(config);
    Display::PrintSeparator(config);

    // ── Identity / Session ─────────────────────────────
    if (config.IsFieldEnabled("userhost")) {
        std::string userHost =
            SystemInfo::GetUsername() + "@" + SystemInfo::GetHostname();
        const auto& dc = config.GetDisplayConfig("userhost");
        Display::PrintInfo(dc.label, userHost, config);
    }

    if (config.IsFieldEnabled("login")) {
        const auto& dc = config.GetDisplayConfig("login");
        Display::PrintInfo(dc.label, SystemInfo::GetLogin(), config);
    }

    if (config.IsFieldEnabled("shell")) {
        const auto& dc = config.GetDisplayConfig("shell");
        Display::PrintInfo(dc.label, SystemInfo::GetShell(), config);
    }

    if (config.IsFieldEnabled("terminal")) {
        const auto& dc = config.GetDisplayConfig("terminal");
        Display::PrintInfo(dc.label, SystemInfo::GetTerminal(), config);
    }

    if (config.IsFieldEnabled("session")) {
        const auto& dc = config.GetDisplayConfig("session");
        Display::PrintInfo(dc.label, SystemInfo::GetSession(), config);
    }

    if (config.IsFieldEnabled("display")) {
        const auto& dc = config.GetDisplayConfig("display");
        Display::PrintInfo(dc.label, SystemInfo::GetDisplay(), config);
    }

    Display::PrintSeparator(config);

    // ── Operating System ───────────────────────────────
    if (config.IsFieldEnabled("os")) {
        const auto& dc = config.GetDisplayConfig("os");
        Display::PrintInfo(dc.label, SystemInfo::GetOS(), config);
    }

    if (config.IsFieldEnabled("kernel")) {
        const auto& dc = config.GetDisplayConfig("kernel");
        Display::PrintInfo(dc.label, SystemInfo::GetKernel(), config);
    }

    if (config.IsFieldEnabled("architecture")) {
        const auto& dc = config.GetDisplayConfig("architecture");
        Display::PrintInfo(dc.label, SystemInfo::GetArchitecture(), config);
    }

    if (config.IsFieldEnabled("chassis")) {
        const auto& dc = config.GetDisplayConfig("chassis");
        Display::PrintInfo(dc.label, SystemInfo::GetChassis(), config);
    }

    if (config.IsFieldEnabled("os_age")) {
        const auto& dc = config.GetDisplayConfig("os_age");
        Display::PrintInfo(dc.label, SystemInfo::GetOSAge(), config);
    }

    Display::PrintSeparator(config);

    // ── Hardware ───────────────────────────────────────
    if (config.IsFieldEnabled("cpu")) {
        const auto& dc = config.GetDisplayConfig("cpu");
        Display::PrintInfo(dc.label, SystemInfo::GetCPU(), config);
    }

    if (config.IsFieldEnabled("gpu")) {
        const auto& dc = config.GetDisplayConfig("gpu");
        Display::PrintInfo(dc.label, SystemInfo::GetGPU(), config);
    }

    if (config.IsFieldEnabled("memory")) {
        const auto& dc = config.GetDisplayConfig("memory");
        Display::PrintInfo(
            dc.label,
            SystemInfo::GetMemory(config.GetStorageUnit()),
            config
        );
    }

    if (config.IsFieldEnabled("swap")) {
        const auto& dc = config.GetDisplayConfig("swap");
        Display::PrintInfo(
            dc.label,
            SystemInfo::GetSwap(config.GetStorageUnit()),
            config
        );
    }

    Display::PrintSeparator(config);

    // ── Environment / Software ─────────────────────────
    if (config.IsFieldEnabled("packages")) {
        const auto& dc = config.GetDisplayConfig("packages");
        Display::PrintInfo(dc.label, SystemInfo::GetPackages(), config);
    }

    if (config.IsFieldEnabled("git")) {
        const auto& dc = config.GetDisplayConfig("git");
        Display::PrintInfo(dc.label, SystemInfo::GetGit(), config);
    }

    if (config.IsFieldEnabled("colours")) {
        const auto& dc = config.GetDisplayConfig("colours");
        Display::PrintInfo(dc.label, SystemInfo::GetColours(), config);
    }

    Display::PrintSeparator(config);

    // ── Network ────────────────────────────────────────
    if (config.IsFieldEnabled("interface")) {
        const auto& dc = config.GetDisplayConfig("interface");
        Display::PrintInfo(dc.label, SystemInfo::GetInterface(), config);
    }

    if (config.IsFieldEnabled("local_ip")) {
        const auto& dc = config.GetDisplayConfig("local_ip");
        Display::PrintInfo(dc.label, SystemInfo::GetLocalIP(), config);
    }

    Display::PrintSeparator(config);

    // ── Time ───────────────────────────────────────────
    if (config.IsFieldEnabled("uptime")) {
        const auto& dc = config.GetDisplayConfig("uptime");
        Display::PrintInfo(dc.label, SystemInfo::GetUptime(), config);
    }

    if (config.IsFieldEnabled("date")) {
        const auto& dc = config.GetDisplayConfig("date");
        Display::PrintInfo(dc.label, SystemInfo::GetDate(), config);
    }

    if (config.IsFieldEnabled("time")) {
        const auto& dc = config.GetDisplayConfig("time");
        Display::PrintInfo(dc.label, SystemInfo::GetTime(), config);
    }

    Display::PrintSeparator(config);

    return 0;
}
