#pragma once
#include <string>
#include <vector>
#include <map>

namespace breadfetch {

    struct ColourConfig {
        std::string reset = "\033[0m";
        std::string bold = "\033[1m";
        std::string label = "\033[36m";  // Cyan
        std::string separator = "\033[34m";  // Blue
        std::string banner = "\033[33m";  // Yellow
    };

    struct DisplayConfig {
        bool enabled = true;
        std::string label;
        std::string format;
    };

    struct AsciiArtConfig {
        std::vector<std::string> lines;
        std::string colour = "\033[33m";
    };

    class Config {
    public:
        Config ( );

        bool LoadFromFile (const std::string& filepath);

        static std::string GetDefaultConfigPath ( );

        static bool CreateDefaultConfig (const std::string& filepath);

        const ColourConfig& GetColours ( ) const {
            return colours;
        }
        const AsciiArtConfig& GetAsciiArt ( ) const {
            return asciiArt;
        }
        const DisplayConfig& GetDisplayConfig (const std::string& field) const;
        bool IsFieldEnabled (const std::string& field) const;
        std::string GetDateFormat ( ) const {
            return dateFormat;
        }
        std::string GetStorageUnit ( ) const {
            return storageUnit;
        }
        int GetSeparatorWidth ( ) const {
            return separatorWidth;
        }
        std::string GetSeparatorChar ( ) const {
            return separatorChar;
        }

        ColourConfig colours;
        AsciiArtConfig asciiArt;
        std::map<std::string, DisplayConfig> displayConfigs;
        std::string dateFormat;
        std::string storageUnit;
        int separatorWidth;
        std::string separatorChar;

    private:
        void SetDefaults ( );
    };

} // namespace breadfetch