//
// Created by runes on 14/12/2025.
//

#include "2XD2/framework/Game.h"
#include "2XD2/framework/SFMLInputHandler.h"

namespace e2XD::framework {

    void Game::run() const {
        running = true;

        while (running && window.isOpen()) {
            // Poll events
            SFMLInputHandler::getInstance()->pollEvents();
            if (activeScene) {
                activeScene->update();
                activeScene->draw();
            }
        }
    }
}
