//
// Created by runes on 14/12/2025.
//

#include "2XD2/framework/Game.h"
#include "2XD2/framework/SFMLInputHandler.h"
#include "2XD2/renderer/Renderer.h"


namespace e2XD::framework {
    void Game::run() {
        running = true;

        renderer::Renderer::getInstance()->initialize(&window);
        SFMLInputHandler::getInstance()->initialize(&window);

        while (running && window.isOpen()) {
            // Poll events
            SFMLInputHandler::getInstance()->pollEvents();
            const auto resized = SFMLInputHandler::getInstance()->isWindowResized();
            if (std::get<0>(resized))
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
                float cameraZoom = 1.0f;
                if (activeCamera)
                {
                    cameraPos = activeScene->getActiveCamera()->getGlobalPosition();
                    cameraZoom = activeCamera->getZoom();
                }
                renderer->setCameraPos({cameraPos.x, cameraPos.y});
                renderer->setCameraZoom(cameraZoom);
                activeScene->draw();
            }
            window.display();
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
