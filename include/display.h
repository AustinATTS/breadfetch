#pragma once
#define DISPLAY_HEADER

#include <string>
#include <vector>

namespace breadfetch {
    class Display {
    public:
        static void PrintBanner ();
        static void PrintInfo (const std::string& label, const std::string& value);
        static void PrintSeperator ();

    private:
        static const char* RESET;
        static const char* BOLD;
        static const char* RED;
        static const char* GREEN;
        static const char* YELLOW;
        static const char* BLUE;
        static const char* MAGENTA;
        static const char* CYAN;
    };
} // namespace breadfetch