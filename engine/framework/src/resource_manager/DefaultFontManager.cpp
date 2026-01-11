//
// Created by rune-suy on 1/11/26.
//

#include "2XD2/framework/resource_manager/DefaultFontManager.h"

#include <fstream>

#include "json.hpp"
#include "2XD2/framework/exceptions/FileLoadingFailedException.h"


namespace e2XD::framework
{
    void DefaultFontManager::loadFontMap(const std::string& fontMapPath)
    {
        nlohmann::json fontMapJson;
        std::ifstream file(fontMapPath);
        if (!file.is_open())
        {
            throw FileLoadingFailedException(fontMapPath,
                                             "DefaultFontManager::loadFontMap(const std::string& fontMapPath)");
        }
        file >> fontMapJson;
        file.close();

        for (const auto& fontEntry : fontMapJson)
        {
            const std::string& name = fontEntry.at("name");
            const std::string& path = fontEntry.at("path");

            sf::Font font;
            if (!font.loadFromFile(path))
            {
                throw FileLoadingFailedException(path,
                                                 "DefaultFontManager::loadFontMap(const std::string& fontMapPath)");
            }

            _loadedFonts[name] = font;
        }
        _loadedFiles.insert(fontMapPath);
    }

    bool DefaultFontManager::loadFontMapIfNotLoaded(const std::string& fontMapPath)
    {
        if (!_loadedFiles.contains(fontMapPath)) {
            loadFontMap(fontMapPath);
        }
    }

    const sf::Font& DefaultFontManager::getFont(const std::string& fontName)
    {
        if (!_loadedFonts.contains(fontName)) {
            throw std::invalid_argument("DefaultFontManager::getFont: Font not found: " + fontName);
        }
        return _loadedFonts.at(fontName);
    }
} // framework
// e2XD
