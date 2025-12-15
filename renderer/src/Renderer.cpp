//
// Created by runes on 14/12/2025.
//

#include "2XD2/renderer/Renderer.h"

#include "2XD2/renderer/exceptions/RendererNotInitializedException.h"

namespace e2XD::renderer {
    void Renderer::initialize(sf::RenderWindow *window) {
        this->window = window;
    }

    void Renderer::draw(sf::Shape &shape, const sf::Vector2f &cameraPos, float cameraZoom) const {
        if (!window) {
            throw RendererNotInitializedException("Renderer::draw(Shape)");
        }

        shape.setPosition((shape.getPosition() - cameraPos) * cameraZoom);
        shape.setScale(cameraZoom, cameraZoom);
        // Render the shape here using your rendering context*
        window->draw(shape);
    }

    void Renderer::draw(sf::Sprite &sprite, const sf::Vector2f &cameraPos, float cameraZoom) const {
        if (!window) {
            throw RendererNotInitializedException("Renderer::draw(Shape)");
        }

        sprite.setPosition((sprite.getPosition() - cameraPos) * cameraZoom);
        sprite.setScale(cameraZoom, cameraZoom);
        // Render the shape here using your rendering context*
        window->draw(sprite);
    }

    void Renderer::draw(sf::Text &text, const sf::Vector2f &cameraPos, float cameraZoom) const {
        if (!window) {
            throw RendererNotInitializedException("Renderer::draw(Shape)");
        }

        text.setPosition((text.getPosition() - cameraPos) * cameraZoom);
        text.setScale(cameraZoom, cameraZoom);
        // Render the shape here using your rendering context*
        window->draw(text);
    }
} // e2XD