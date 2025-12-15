//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_INPUTMANAGER_H
#define INC_2XD2_ENGINE_INPUTMANAGER_H
#include <memory>

#include "IInputHandler.h"


namespace sf {
    class Event;
}

namespace e2XD::framework {
    /**
     * Singleton class to manage input from keyboard, mouse, and other devices
     */
    class SFMLInputHandler : public IInputHandler {
        inline static SFMLInputHandler *_instance=nullptr;

        SFMLInputHandler() = default;

    public:
        SFMLInputHandler(const SFMLInputHandler &) = delete;

        ~SFMLInputHandler() override;

        SFMLInputHandler &operator=(const SFMLInputHandler &) = delete;

        static SFMLInputHandler *getInstance();
    };
} // core

#endif //INC_2XD2_ENGINE_INPUTMANAGER_H
