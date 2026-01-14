// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

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

            _loadedFonts[name];
            if (!_loadedFonts.at(name).loadFromFile(path))
            {
                throw FileLoadingFailedException(path,
                                                 "DefaultFontManager::loadFontMap(const std::string& fontMapPath)");
            }

        }
        _loadedFiles.insert(fontMapPath);
    }

    bool DefaultFontManager::loadFontMapIfNotLoaded(const std::string& fontMapPath)
    {
        if (!_loadedFiles.contains(fontMapPath)) {
            loadFontMap(fontMapPath);
            return true;
        }
        return false;
    }

    const sf::Font& DefaultFontManager::getFont(const std::string& fontName)
    {
        if (!_loadedFonts.contains(fontName)) {
            throw std::invalid_argument("DefaultFontManager::getFont: Font not found: " + fontName);
        }
        return _loadedFonts.at(fontName);
    }

    void DefaultFontManager::loadFont(const std::string& fontName, const std::string& filePath)
    {
        _loadedFonts[fontName];
        if (!_loadedFonts.at(fontName).loadFromFile(filePath))
        {
            throw FileLoadingFailedException(filePath,
                                             "DefaultFontManager::loadFont(const std::string& fontName, const std::string& filePath)");
        }
        _loadedFiles.insert(filePath);
    }
} // framework

// e2XD
