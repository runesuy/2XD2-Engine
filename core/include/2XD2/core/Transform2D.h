//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_TRANSFORM2D_H
#define INC_2XD2_ENGINE_TRANSFORM2D_H
#include "Vec2.h"

namespace e2XD::core {
    class Transform2D {
        Vec2 position={0.0, 0.0};
        Vec2 scale={1.0, 1.0};
        double rotation=0.0;

    public:
        Transform2D() = default;

        [[nodiscard]] const Vec2 &getPosition() const;

        void setPosition(const Vec2 &position);

        [[nodiscard]] const Vec2 &getScale() const;

        void setScale(const Vec2 &scale);

        [[nodiscard]] double getRotation() const;

        void setRotation(double rotation);
    };
} // core

#endif //INC_2XD2_ENGINE_TRANSFORM2D_H