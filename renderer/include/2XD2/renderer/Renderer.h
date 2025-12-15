//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_RENDERER_H
#define INC_2XD2_ENGINE_RENDERER_H
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>

namespace e2XD::renderer {

    class Renderer {
        sf::RenderWindow* window = nullptr;
    public:
        void initialize(sf::RenderWindow* window);

        void draw(sf::Sprite& sprite, const sf::Vector2f& cameraPos, float cameraZoom) const;

        void draw(sf::Text& text, const sf::Vector2f& cameraPos, float cameraZoom) const;

        void draw(sf::Shape& shape, const sf::Vector2f& cameraPos, float cameraZoom) const;

    };
}


#endif //INC_2XD2_ENGINE_RENDERER_H