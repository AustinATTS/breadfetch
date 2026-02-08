#include "display.h"
#include <iostream>
#include <iomanip>

namespace breadfetch {
    const char* Display::RESET = "\033[0m";
    const char* Display::BOLD = "\033[1m";
    const char* Display::RED = "\033[31m";
    const char* Display::GREEN = "\033[32m";
    const char* Display::YELLOW = "\033[33m";
    const char* Display::BLUE = "\033[34m";
    const char* Display::MAGENTA = "\033[35m";
    const char* Display::CYAN = "\033[36m";

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