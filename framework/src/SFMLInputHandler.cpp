//
// Created by runes on 14/12/2025.
//

#include "2XD2/framework/SFMLInputHandler.h"

namespace e2XD::framework {
    SFMLInputHandler* SFMLInputHandler::getInstance() {
        return _instance;
    }

    SFMLInputHandler::~SFMLInputHandler() {
        if (_instance) delete _instance;
    }
} // core