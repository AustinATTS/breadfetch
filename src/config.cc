#include "config.h"
#include "toml.hpp"
#include <fstream>
#include <iostream>
#include <filesystem>
#include <cstdlib>

namespace breadfetch {

void loadColours (Config* cfg, const toml::value& config);
void loadDisplay (Config* cfg, const toml::value& config);
void loadAsciiArt (Config* cfg, const toml::value& config);
void loadFormats (Config* cfg, const toml::value& config);

Config::Config ( ) {
    SetDefaults();
}

void Config::SetDefaults ( ) {
    colours.reset     = "\033[0m";
    colours.bold      = "\033[1m";
    colours.label     = "\033[36m"; // Cyan
    colours.separator = "\033[34m"; // Blue
    colours.banner    = "\033[33m"; // Yellow

    displayConfigs = {
        {"userhost",     {true, "User@Host", ""}},
        {"login",        {true, "Login", ""}},
        {"shell",        {true, "Shell", ""}},
        {"terminal",     {true, "Terminal", ""}},
        {"session",      {true, "Session", ""}},
        {"display",      {true, "Display", ""}},

        {"os",           {true, "OS", ""}},
        {"kernel",       {true, "Kernel", ""}},
        {"architecture", {true, "Architecture", ""}},
        {"chassis",      {true, "Chassis", ""}},
        {"os_age",       {true, "OS Age", ""}},

        {"cpu",          {true, "CPU", ""}},
        {"gpu",          {true, "GPU", ""}},
        {"memory",       {true, "Memory", ""}},
        {"swap",         {true, "Swap", ""}},

        {"packages",     {true, "Packages", ""}},
        {"git",          {true, "Git", ""}},
        {"colours",      {true, "Colours", ""}},

        {"interface",    {true, "Interface", ""}},
        {"local_ip",     {true, "Local IP", ""}},

        {"uptime",       {true, "Uptime", ""}},
        {"date",         {true, "Date", ""}},
        {"time",         {true, "Time", ""}},
    };

    dateFormat     = "%Y-%m-%d %H:%M:%S";
    storageUnit    = "MB"; // B, KB, MB, GB
    separatorWidth = 45;
    separatorChar  = "─";

    asciiArt.colour = "\033[33m";
    asciiArt.lines = {
        " ____                     _ _____    _       _",
        "| __ ) _ __ ___  __ _  __| |  ___|__| |_ ___| |__",
        "|  _ \\| '__/ _ \\/ _` |/ _` | |_ / _ \\ __/ __| '_ \\",
        "| |_) | | |  __/ (_| | (_| |  _|  __/ || (__| | | |",
        "|____/|_|  \\___/\\__,_|\\__,_|_|  \\___|\\_\\___|_| |_|"
    };
}

bool Config::LoadFromFile (const std::string& filepath) {
    try {
        const auto config = toml::parse(filepath);
        loadColours(this, config);
        loadDisplay(this, config);
        loadAsciiArt(this, config);
        loadFormats(this, config);
        return true;
    }
    catch (const std::exception& e) {
        std::cerr << "Error loading config: " << e.what() << std::endl;
        return false;
    }
}

void loadColours (Config* cfg, const toml::value& config) {
    if (!config.contains("colors")) {
        return;
    }
    const auto& t = toml::find(config, "colors");

    if (t.contains("label")) {
        cfg->colours.label     = toml::find<std::string>(t, "label");
    }
    if (t.contains("separator")) {
        cfg->colours.separator = toml::find<std::string>(t, "separator");
    }
    if (t.contains("banner")) {
        cfg->colours.banner    = toml::find<std::string>(t, "banner");
    }
}

void loadDisplay (Config* cfg, const toml::value& config) {
    if (!config.contains("display")) {
        return;
    }
    const auto& table = toml::find(config, "display");

    for (auto& [key, dc] : cfg->displayConfigs) {
        if (!table.contains(key)) {
            continue;
        }

        const auto& v = toml::find(table, key);
        if (v.is_boolean()) {
            dc.enabled = toml::get<bool>(v);
        }
        else {
            if (v.is_table()) {
                if (v.contains("enabled")) {
                    dc.enabled = toml::find<bool>(v, "enabled");
                }
                if (v.contains("label")) {
                    dc.label   = toml::find<std::string>(v, "label");
                }
                if (v.contains("format")) {
                    dc.format  = toml::find<std::string>(v, "format");
                }
            }
        }
    }
}

void loadAsciiArt (Config* cfg, const toml::value& config) {
    if (!config.contains("ascii")) {
        return;
    }
    const auto& t = toml::find(config, "ascii");

    if (t.contains("color")) {
        cfg->asciiArt.color = toml::find<std::string>(t, "color");
    }

    if (t.contains("art")) {
        auto art = toml::find<std::vector<std::string>>(t, "art");
        if (!art.empty()) {
            cfg->asciiArt.lines = art;
        }
    }
}

void loadFormats (Config* cfg, const toml::value& config) {
    if (!config.contains("formats")) {
        return;
    }
    const auto& t = toml::find(config, "formats");

    if (t.contains("date")) {
        cfg->dateFormat     = toml::find<std::string>(t, "date");
    }
    if (t.contains("storage_unit")) {
        cfg->storageUnit    = toml::find<std::string>(t, "storage_unit");
    }
    if (t.contains("separator_width")) {
        cfg->separatorWidth = toml::find<int>(t, "separator_width");
    }
    if (t.contains("separator_char")) {
        cfg->separatorChar  = toml::find<std::string>(t, "separator_char");
    }
}

const DisplayConfig& Config::GetDisplayConfig (const std::string& field) const {
    static DisplayConfig empty{false, "", ""};
    auto it = displayConfigs.find(field);
    return it != displayConfigs.end() ? it->second : empty;
}

bool Config::IsFieldEnabled (const std::string& field) const {
    auto it = displayConfigs.find(field);
    return it != displayConfigs.end() && it->second.enabled;
}

std::string Config::GetDefaultConfigPath ( ) {
    if (const char* xdg = std::getenv("XDG_CONFIG_HOME")) {
        return std::string(xdg) + "/breadfetch/config.toml";
    }
    if (const char* home = std::getenv("HOME")) {
        return std::string(home) + "/.config/breadfetch/config.toml";
    }
    return "";
}

bool Config::CreateDefaultConfig (const std::string& filepath) {
    std::filesystem::create_directories(std::filesystem::path(filepath).parent_path());

    std::ofstream file(filepath);
    if (!file.is_open()) {
        return false;
    }

    file << R"(# breadfetch config

[colors]
label = "\u001b[36m"
separator = "\u001b[34m"
banner = "\u001b[33m"

[display]
userhost  = true
login     = true
shell     = true
terminal  = true
session   = true
display   = true

os           = true
kernel       = true
architecture = true
chassis      = true
os_age       = true

cpu     = true
gpu     = true
memory  = true
swap    = true

packages = true
git      = true
colours  = true

interface = true
local_ip = true

uptime = true
date   = true
time   = true

[formats]
date = "%Y-%m-%d %H:%M:%S"
storage_unit = "MB"
separator_width = 45
separator_char = "─"

[ascii]
color = "\u001b[33m"
art = [
  " ____                     _ _____    _       _",
  "| __ ) _ __ ___  __ _  __| |  ___|__| |_ ___| |__",
  "|  _ \\| '__/ _ \\/ _` |/ _` | |_ / _ \\ __/ __| '_ \\",
  "| |_) | | |  __/ (_| | (_| |  _|  __/ || (__| | | |",
  "|____/|_|  \\___/\\__,_|\\__,_|_|  \\___|\\_\\___|_| |_|"
]
)";

    return true;
}

} // namespace breadfetch
