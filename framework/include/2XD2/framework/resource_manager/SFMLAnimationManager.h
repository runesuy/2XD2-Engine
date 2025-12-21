//
// Created by rune-suy on 12/18/25.
//

#ifndef FLATLAND_ANIMATIONMANAGER_H
#define FLATLAND_ANIMATIONMANAGER_H
#include <set>
#include <string>
#include <unordered_map>

#include "2XD2/framework/AnimationMap.h"

namespace e2XD::framework
{
    /**
     * Animation manager implementation using SFML Textures.
     */
    class SFMLAnimationManager final
    {
        std::unordered_map<std::string, AnimationMap> loadedAnimationMaps;

        std::set<std::string> loadedFiles;

    public:
        SFMLAnimationManager()=default;
        ~SFMLAnimationManager() = default;

        [[nodiscard]] const AnimationMap& getAnimationMap(const std::string& name) const;

        /**
         * Load animations in the manager using a json config file.
         * Json format:
         * @code
         * {
         *    "animation-map-name": "example-animations",
         *    "animations": [
         *      {
         *        "name": "animation-1",
         *       "frame-duration": 0.1,
         *       "repeat": false,
         *          "frames": [
         *          "texture_0",
         *          "texture_1",
         *          "texture_2,"
         *        ]
         *      }
         *    ]
         * }
         *
         * The mentioned textures need to be textures present in SFMLTextureManager
         *
         * @endcode
         *
         * @param jsonFilePath
         */
        void loadJsonAnimationConfig(const std::string& jsonFilePath);


        bool isJsonAnimationLoaded(const std::string& jsonFilePath) const;

        bool loadJsonAnimationConfigIfNotLoaded(const std::string& jsonFilePath);
    };
}

#endif //FLATLAND_ANIMATIONMANAGER_H
