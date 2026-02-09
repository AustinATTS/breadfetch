#include "display.h"
#include <iostream>
#include <iomanip>

namespace breadfetch {
    const char* Display::RESET = "\033[0m";
    const char* Display::BOLD = "\033[1m";
    const char* Display::ITALIC = "\033[3m";
    const char* Display::UNDERLINE = "\033[4m";
    const char* Display::BLINK = "\033[5m";
    const char* Display::VIDEO = "\033[7m";
    const char* Display::CONCEAL = "\033[8m";
    const char* Display::CROSSED = "\033[9m";

    const char* Display::BLACK = "\033[30m";
    const char* Display::RED = "\033[31m";
    const char* Display::GREEN = "\033[32m";
    const char* Display::YELLOW = "\033[33m";
    const char* Display::BLUE = "\033[34m";
    const char* Display::MAGENTA = "\033[35m";
    const char* Display::CYAN = "\033[36m";
    const char* Display::WHITE = "\033[37m";
    const char* Display::DEFAULT = "\033[39m";

    const char* Display::BBLACK = "\033[40m";
    const char* Display::BRED = "\033[41m";
    const char* Display::BGREEN = "\033[42m";
    const char* Display::BYELLOW = "\033[43m";
    const char* Display::BBLUE = "\033[44m";
    const char* Display::BMAGENTA = "\033[45m";
    const char* Display::BCYAN = "\033[46m";
    const char* Display::BWHITE = "\033[47m";
    const char* Display::BDEFAULT = "\033[49m";

    void Display::PrintBanner ( ) {
        std::cout << BOLD << YELLOW << R"(
    ____  ____  _________    ____  __________________________  __
   / __ )/ __ \/ ____/   |  / __ \/ ____/ ____/_  __/ ____/ / / /
  / __  / /_/ / __/ / /| | / / / / /_  / __/   / / / /   / /_/ /
 / /_/ / _, _/ /___/ ___ |/ /_/ / __/ / /___  / / / /___/ __  /
/_____/_/ |_/_____/_/  |_/_____/_/   /_____/ /_/  \____/_/ /_/
)" << RESET << std::endl;
    }

    void Display::PrintInfo (const std::string& label, const std::string& value) {
        std::cout << BOLD << CYAN << std::setw(15) << std::left << label << RESET
                  << ": " << value << std::endl;
    }

    void Display::PrintSeparator ( ) {
        std::cout << BOLD << BLUE << "─────────────────────────────────────────────" << RESET << std::endl;
    }
} // namespace breadfetch