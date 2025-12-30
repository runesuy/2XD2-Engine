//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_TRANSFORM2D_H
#define INC_2XD2_ENGINE_TRANSFORM2D_H
#include "Vec2f.h"

namespace e2XD::framework
{
    /**
     * Defines a 2D transformation with position, scale and rotation.
     */
    class Transform2D
    {
        Vec2f position = {0.0, 0.0};
        Vec2f scale = {1.0, 1.0};
        double rotation = 0.0;

    public:
        Transform2D() = default;

        [[nodiscard]] const Vec2f& getPosition() const;

        void setPosition(const Vec2f& position);

        [[nodiscard]] const Vec2f& getScale() const;

        void setScale(const Vec2f& scale);

        [[nodiscard]] double getRotation() const;

        void setRotation(double rotation);
    };
} // core

#endif //INC_2XD2_ENGINE_TRANSFORM2D_H
