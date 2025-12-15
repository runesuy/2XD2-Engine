//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_NODE2D_H
#define INC_2XD2_ENGINE_NODE2D_H
#include "Node.h"
#include "Transform2D.h"
#include "Vec2.h"

namespace e2XD::core {
    class Node2D : public Node {
        Transform2D globalTransform;
        Transform2D localTransform;

    public:
        Node2D() = default;

        [[nodiscard]] const Vec2 &getGlobalPosition() const;

        void setGlobalPosition(const Vec2 &position);

        [[nodiscard]] const Vec2 &getLocalPosition() const;

        void setLocalPosition(const Vec2 &position);

        [[nodiscard]] const Vec2 &getGlobalScale() const;

        void setGlobalScale(const Vec2 &scale);

        [[nodiscard]] const Vec2 &getLocalScale() const;

        void setLocalScale(const Vec2 &scale);

        [[nodiscard]] double getGlobalRotation() const;

        void setGlobalRotation(double rotation);

        [[nodiscard]] double getLocalRotation() const;

        void setLocalRotation(double rotation);
    };
} // e2XD

#endif //INC_2XD2_ENGINE_NODE2D_H
