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
        sf::Vector2f cameraPos;
        float cameraZoom = 1.0f;

        inline static Renderer* _instance = nullptr;

        Renderer()=default;

        sf::Color backgroundColor = sf::Color::Black;
    public:
        Renderer(const Renderer&) = delete;
        Renderer(Renderer&&) = delete;
        virtual ~Renderer()=default;
        Renderer& operator=(const Renderer&) = delete;
        Renderer& operator=(Renderer&&) = delete;

        void initialize(sf::RenderWindow* window);

        static Renderer* getInstance();

        void clearWindow() const;

        void draw(const sf::Drawable& drawable, const sf::Vector2f &position, const sf::Vector2f& cameraPos, float cameraZoom) const;

        void draw(const sf::Drawable& drawable, const sf::Vector2f &position) const;

        void setBackgroundColor(const sf::Color& color);

        void setCameraPos(const sf::Vector2f& newCameraPos);

        void setCameraZoom(float newCameraZoom);

    };
}


#endif //INC_2XD2_ENGINE_RENDERER_H