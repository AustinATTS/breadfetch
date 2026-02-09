#pragma once

#include <string>
#include "config.h"

namespace breadfetch {
    class Display {
    public:
        static void PrintBanner (const Config& config);
        static void PrintInfo (const std::string& label, const std::string& value, const Config& config);
        static void PrintSeparator (const Config& config);

    private:
        static const char* RESET;
        static const char* BOLD;
        static const char* ITALIC;
        static const char* UNDERLINE;
        static const char* BLINK;
        static const char* VIDEO;
        static const char* CONCEAL;
        static const char* CROSSED;

        static const char* BLACK;
        static const char* RED;
        static const char* GREEN;
        static const char* YELLOW;
        static const char* BLUE;
        static const char* MAGENTA;
        static const char* CYAN;
        static const char* WHITE;
        static const char* DEFAULT;

        static const char* BBLACK;
        static const char* BRED;
        static const char* BGREEN;
        static const char* BYELLOW;
        static const char* BBLUE;
        static const char* BMAGENTA;
        static const char* BCYAN;
        static const char* BWHITE;
        static const char* BDEFAULT;
    };
} // namespace breadfetch