//
// Created by runes on 14/12/2025.
//

#include "2XD2/renderer/Renderer.h"

#include "2XD2/renderer/exceptions/NotInitializedException.h"

namespace e2XD::renderer
{
    void Renderer::initialize(sf::RenderWindow* window)
    {
        this->window = window;
    }

    void Renderer::draw(sf::Shape& shape, const sf::Vector2f& cameraPos, float cameraZoom) const
    {
        if (!window)
        {
            throw NotInitializedException("Renderer::draw(Shape)");
        }

        auto newPos = (shape.getPosition() - cameraPos) * cameraZoom + sf::Vector2f{
            static_cast<float>(window->getSize().x) / 2, static_cast<float>(window->getSize().y) / 2
        };
        shape.setPosition(newPos);
        shape.setScale(cameraZoom, cameraZoom);
        // Render the shape here using your rendering context*
        window->draw(shape);
    }

    void Renderer::draw(sf::Sprite& sprite, const sf::Vector2f& cameraPos, float cameraZoom) const
    {
        if (!window)
        {
            throw NotInitializedException("Renderer::draw(Shape)");
        }

        auto newPos = (sprite.getPosition() - cameraPos) * cameraZoom + sf::Vector2f{
            static_cast<float>(window->getSize().x) / 2, static_cast<float>(window->getSize().y) / 2
        };
        sprite.setPosition(newPos);
        sprite.setScale(cameraZoom, cameraZoom);
        // Render the shape here using your rendering context*
        window->draw(sprite);
    }

    void Renderer::draw(sf::Text& text, const sf::Vector2f& cameraPos, float cameraZoom) const
    {
        if (!window)
        {
            throw NotInitializedException("Renderer::draw(Shape)");
        }

        auto newPos = (text.getPosition() - cameraPos) * cameraZoom + sf::Vector2f{
            static_cast<float>(window->getSize().x) / 2, static_cast<float>(window->getSize().y) / 2
        };
        text.setPosition(newPos);
        text.setScale(cameraZoom, cameraZoom);
        // Render the shape here using your rendering context*
        window->draw(text);
    }

    void Renderer::setBackgroundColor(const sf::Color& color)
    {
        backgroundColor = color;
    }


    Renderer* Renderer::getInstance()
    {
        if (!_instance)
        {
            _instance = new Renderer();
        }
        return _instance;
    }

    void Renderer::clearWindow() const
    {
        window->clear(backgroundColor);
    }
} // e2XD
