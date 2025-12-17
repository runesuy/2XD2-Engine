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

    void Renderer::draw(const sf::Drawable& drawable, const sf::Vector2f &position, const sf::Vector2f& cameraPos, float cameraZoom) const
    {
        if (!window)
        {
            throw NotInitializedException("Renderer::draw(Shape)");
        }

        sf::Vector2f transformedPos = {position.x, -position.y};
        sf::Vector2f transformedCameraPos = {cameraPos.x, -cameraPos.y};
        auto newPos = (transformedPos -transformedCameraPos) * cameraZoom + sf::Vector2f{
            static_cast<float>(window->getSize().x) / 2, static_cast<float>(window->getSize().y) / 2
        };

        sf::Transform transform;
        // Chain the transformations
        transform.translate(newPos) // 3. Move to world position
                 .rotate(1)    // 2. Rotate around the origin
                 .scale(cameraZoom, cameraZoom);       // 1. Scale the local coordinates

        sf::RenderStates states;
        states.transform = transform;
        // Render the shape here using your rendering context*
        window->draw(drawable, transform);
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

    void Renderer::setCameraPos(const sf::Vector2f& newCameraPos)
    {
        cameraPos = newCameraPos;
    }

    void Renderer::setCameraZoom(float newCameraZoom)
    {
        cameraZoom = newCameraZoom;
    }


    void Renderer::draw(const sf::Drawable& drawable, const sf::Vector2f& position) const
    {
        draw(drawable, position, cameraPos, cameraZoom);
    }


} // e2XD
