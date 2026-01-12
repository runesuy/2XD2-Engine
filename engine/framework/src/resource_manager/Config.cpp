//
// Created by rune-suy on 1/10/26.
//

#include "2XD2/framework/resource_manager/Config.h"

#include "2XD2/core/exceptions/NotInitializedException.h"

namespace e2XD::framework
{
    void Resources::Config::initialize(IConfigManager* configManager)
    {
        _configManager = configManager;
    }

    const nlohmann::json& Resources::Config::loadConfig(const std::string& configPath)
    {
        if (!_configManager)
            throw core::NotInitializedException("Resources::Config::loadConfig: ConfigManager not initialized.", "Resources::Config::loadConfig(const std::string& configPath)");
        return _configManager->loadConfig(configPath);
    }

    void Resources::Config::closeConfig(const std::string& configPath)
    {
        if (!_configManager)
            throw std::runtime_error("Resources::Config::closeConfig: ConfigManager not initialized.");
        _configManager->closeConfig(configPath);
    }
} // framework