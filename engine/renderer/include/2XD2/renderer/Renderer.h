//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_RENDERER_H
#define INC_2XD2_ENGINE_RENDERER_H
#include <unordered_map>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Shape.hpp>
#include "RenderCommand.h"
#include "2XD2/core/Camera.h"
#include "2XD2/core/RenderLayer.h"

namespace e2XD::renderer
{
    /**
     * Singleton class responsible for rendering objects to the screen. Using the rendering pipeline.
     */
    class Renderer
    {
        sf::RenderWindow* window = nullptr;
        core::Camera* _camera = nullptr;

        inline static Renderer* _instance = nullptr;

        Renderer() = default;

        std::unordered_map<RenderLayer, std::vector<RenderCommand>> renderQueue;

    public:
        Renderer(const Renderer&) = delete;
        Renderer(Renderer&&) = delete;
        virtual ~Renderer() = default;
        Renderer& operator=(const Renderer&) = delete;
        Renderer& operator=(Renderer&&) = delete;

        void initialize(sf::RenderWindow* window);

        static Renderer* getInstance();

        void clearWindow() const;

        void submit(const RenderCommand& renderCommand);

        void flush(const core::Camera* worldCamera);
    };
}


#endif //INC_2XD2_ENGINE_RENDERER_H
