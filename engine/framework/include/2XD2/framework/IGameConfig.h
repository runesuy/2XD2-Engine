//
// Created by rune-suy on 12/20/25.
//

#ifndef INC_2XD2_ENGINE_IGAMECONFIG_H
#define INC_2XD2_ENGINE_IGAMECONFIG_H
#include "input/IInputHandler.h"
#include "resource_manager/IAnimationManager.h"
#include "resource_manager/ITextureManager.h"


namespace e2XD::framework
{
    /**
     * Game configuration interface to provide various managers to the framework's Game implementation.
     */
    class IGameConfig
    {
    public:
        virtual ~IGameConfig() = default;

        [[nodiscard]] virtual IInputHandler* getInputHandler() const =0;

        [[nodiscard]] virtual IAnimationManager* getAnimationManager() const =0;

        [[nodiscard]] virtual ITextureManager* getTextureManager() const =0;
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_IGAMECONFIG_H
