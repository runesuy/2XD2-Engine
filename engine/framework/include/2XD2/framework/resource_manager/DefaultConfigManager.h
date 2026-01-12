//
// Created by rune-suy on 1/12/26.
//

#ifndef INC_2XD2_ENGINE_DEFAULTCONFIGMANAGER_H
#define INC_2XD2_ENGINE_DEFAULTCONFIGMANAGER_H
#include "IConfigManager.h"


namespace e2XD::framework
{
    class DefaultConfigManager : public IConfigManager
    {
        std::unordered_map<std::string, nlohmann::json> _loadedFiles;
    public:
        const nlohmann::json& loadConfig(const std::string& configPath) override;

        void closeConfig(const std::string& configPath) override;
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_DEFAULTCONFIGMANAGER_H
