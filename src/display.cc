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

    void Display::PrintBanner (const Config& config) {
        const auto& asciiArt = config.GetAsciiArt();
        const auto& colours = config.GetColours();

        std::cout << colours.bold << asciiArt.colour;
        for (const auto& line : asciiArt.lines) {
            std::cout << line << std::endl;
        }
        std::cout << colours.reset << std::endl;
    }

    void Display::PrintInfo (const std::string& label, const std::string& value, const Config& config) {
        const auto& colours = config.GetColours();
        std::cout << colours.bold << colours.label << std::setw(15) << std::left << label << colours.reset
                  << ": " << value << std::endl;
    }

    void Display::PrintSeparator (const Config& config) {
        const auto& colours = config.GetColours();
        int width = config.GetSeparatorWidth();
        std::string sepChar = config.GetSeparatorChar();

        std::cout << colours.bold << colours.separator;
        for (int i = 0; i < width; i++) {
            std::cout << sepChar;
        }
        std::cout << colours.reset << std::endl;
    }
} // namespace breadfetch