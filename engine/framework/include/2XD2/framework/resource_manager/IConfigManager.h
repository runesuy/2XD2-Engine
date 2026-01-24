// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/12/26.
//

#ifndef INC_2XD2_ENGINE_ICONFIGMANAGER_H
#define INC_2XD2_ENGINE_ICONFIGMANAGER_H
#include <string>
#include <nlohmann/json.hpp>


namespace e2XD::framework
{
    class IConfigManager
    {
    public:
        virtual ~IConfigManager() = default;

        /**
         * Load a configuration file and return its JSON representation.
         * @param configPath
         * @return returns the JSON object representing the configuration.
         */
        virtual const nlohmann::json& loadConfig(const std::string& configPath) = 0;

        /**
         * Close the configuration file and free the associated resources.
         * @param configPath
         */
        virtual void closeConfig(const std::string& configPath) = 0;
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_ICONFIGMANAGER_H
