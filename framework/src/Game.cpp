//
// Created by runes on 14/12/2025.
//

#include "2XD2/framework/Game.h"
#include "2XD2/framework/SFMLInputHandler.h"


namespace e2XD::framework {

    void Game::run() {
        running = true;

        while (running && window.isOpen()) {
            // Poll events
            SFMLInputHandler::getInstance()->pollEvents();
            const auto resized = SFMLInputHandler::getInstance()->isWindowResized();
            if (std::get<0>(resized))
            {
                sf::FloatRect visibleArea(0, 0, std::get<1>(resized), std::get<2>(resized));
                window.setView(sf::View(visibleArea));
            }

            if (activeScene) {
                activeScene->update();
                activeScene->draw();
            }
        }
    }
}
