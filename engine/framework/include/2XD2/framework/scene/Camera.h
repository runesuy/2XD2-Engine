//
// Created by runes on 15/12/2025.
//

#ifndef INC_2XD2_ENGINE_CAMERA_H
#define INC_2XD2_ENGINE_CAMERA_H
#include "../nodes/Node2D.h"

namespace e2XD::framework
{
    /**
     * Camera node to define the view in a 2D scene.
     */
    class Camera : public Node2D
    {
        float zoom = 1;
        core::Vec2f size = {800, 600};

    public:
        Camera() = default;
        ~Camera() override = default;

        /**
         *
         * @return the zoom level of the camera. 1.0f is default, less than 1.0f is zoomed in, greater than 1.0f is zoomed out.
         */
        [[nodiscard]] float getZoom() const;

        /**
         * Set the zoom level of the camera. 1.0f is default, less than 1.0f is zoomed in, greater than 1.0f is zoomed out.
         * @param newZoom
         */
        void setZoom(float newZoom);

        /**
         * Set the size of the camera view in world units.
         * @param newSize
         */
        void setSize(const core::Vec2f& newSize);

        /**
         *
         * @return the size of the camera view in world units.
         */
        [[nodiscard]] const core::Vec2f& getSize() const;
    };
} // core
// e2XD

#endif //INC_2XD2_ENGINE_CAMERA_H
