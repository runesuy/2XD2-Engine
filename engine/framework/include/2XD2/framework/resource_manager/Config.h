//
// Created by rune-suy on 1/10/26.
//

#ifndef INC_2XD2_ENGINE_CONFIG_H
#define INC_2XD2_ENGINE_CONFIG_H
#include <string>

#include "IConfigManager.h"
#include "json.hpp"
#include "Resources.h"

namespace e2XD::framework
{
    class Resources::Config
    {
        inline static IConfigManager* _configManager = nullptr;
    public:
        virtual ~Config() = default;
        static void initialize(IConfigManager* configManager);

        static const nlohmann::json& loadConfig(const std::string& configPath);

        static void closeConfig(const std::string& configPath);
    };
}


#endif //INC_2XD2_ENGINE_CONFIG_H
