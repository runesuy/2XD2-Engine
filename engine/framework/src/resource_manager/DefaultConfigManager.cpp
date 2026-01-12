//
// Created by rune-suy on 1/12/26.
//

#include "2XD2/framework/resource_manager/DefaultConfigManager.h"
#include "2XD2/framework/exceptions/FileLoadingFailedException.h"
#include <fstream>


namespace e2XD::framework
{
    const nlohmann::json& DefaultConfigManager::loadConfig(const std::string& configPath)
    {
        std::ifstream file(configPath);
        if (!file.is_open())
        {
            throw FileLoadingFailedException(configPath,
                                             "DefaultConfigManager::loadConfig(const std::string& configPath)");
        }
        nlohmann::json configJson;
        file >> configJson;
        file.close();
        _loadedFiles[configPath] = configJson;
        return _loadedFiles.at(configPath);
    }

    void DefaultConfigManager::closeConfig(const std::string& configPath)
    {
        _loadedFiles.erase(configPath);
    }
} // framework
// e2XD
