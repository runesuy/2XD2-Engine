// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/21/25.
//

#ifndef INC_2XD2_ENGINE_ANIMATIONS_H
#define INC_2XD2_ENGINE_ANIMATIONS_H
#include <string>

#include "IAnimationManager.h"
#include "Resources.h"
#include "AnimationMap.h"

namespace e2XD::framework
{
    class Resources::Animations final
    {
        inline static IAnimationManager* _animationManager = nullptr;

    public:
        static void initialize(IAnimationManager* animationManager);


        [[nodiscard]] static const AnimationMap& getAnimationMap(const std::string& name);

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
        static void loadJsonAnimationConfig(const std::string& jsonFilePath);


        [[nodiscard]] static bool isJsonAnimationLoaded(const std::string& jsonFilePath);

        static bool loadJsonAnimationConfigIfNotLoaded(const std::string& jsonFilePath);
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_ANIMATIONS_H
