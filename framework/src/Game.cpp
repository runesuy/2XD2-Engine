//
// Created by runes on 14/12/2025.
//

#include "2XD2/framework/Game.h"

#include "2XD2/core/Time.h"
#include "2XD2/framework/SFMLInputHandler.h"
#include "2XD2/renderer/Renderer.h"


namespace e2XD::framework {
    void Game::run() {
        running = true;
        window.setKeyRepeatEnabled(false);

        renderer::Renderer::getInstance()->initialize(&window);
        const auto inputHandler = SFMLInputHandler::getInstance();
        inputHandler->initialize(&window);

        while (running && window.isOpen()) {
            core::Time::tick();
            // Poll events
            SFMLInputHandler::getInstance()->pollEvents();
            if (const auto& resized = SFMLInputHandler::getInstance()->isWindowResized(); std::get<0>(resized))
            {
                sf::FloatRect visibleArea(0, 0, std::get<1>(resized), std::get<2>(resized));
                window.setView(sf::View(visibleArea));
            }

            if (SFMLInputHandler::getInstance()->isWindowClosed()) window.close();

            if (activeScene) {
                activeScene->update();
                const auto& renderer = renderer::Renderer::getInstance();
                renderer->clearWindow();
                const auto& activeCamera = activeScene->getActiveCamera();
                core::Vec2 cameraPos = {0,0};
                activeScene->draw();
            }
            renderer::Renderer::getInstance()->flush(activeScene ? activeScene->getActiveCamera() : nullptr);
            window.display();
            inputHandler->newFrame();
        }
    }

    void Game::setWindowTitle(const std::string& title)
    {
        window.setTitle(title);
    }

    void Game::setActiveScene(std::unique_ptr<core::Scene>&& scene)
    {
        activeScene = std::move(scene);
        activeScene->create();
    }

}
