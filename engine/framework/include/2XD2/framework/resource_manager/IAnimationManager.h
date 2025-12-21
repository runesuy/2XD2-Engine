//
// Created by rune-suy on 12/21/25.
//

#ifndef INC_2XD2_ENGINE_IANIMATIONMANAGER_H
#define INC_2XD2_ENGINE_IANIMATIONMANAGER_H
#include "2XD2/framework/AnimationMap.h"


namespace e2XD::framework
{
    /**
     * Animation manager interface.
     * Can be implemented and passed to Resources::Animations to provide custom animation management.
     */
    class IAnimationManager
    {
    public:
        virtual ~IAnimationManager() = default;

        [[nodiscard]] virtual const AnimationMap& getAnimationMap(const std::string& name) const =0;

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
        virtual void loadJsonAnimationConfig(const std::string& jsonFilePath) =0;

        [[nodiscard]] virtual bool isJsonAnimationLoaded(const std::string& jsonFilePath) const =0;

        virtual bool loadJsonAnimationConfigIfNotLoaded(const std::string& jsonFilePath) =0;
    };
} // framework
// e2DX

#endif //INC_2XD2_ENGINE_IANIMATIONMANAGER_H
