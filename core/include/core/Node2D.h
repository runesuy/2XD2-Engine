//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_NODE2D_H
#define INC_2XD2_ENGINE_NODE2D_H
#include "Node.h"
#include "Vec2.h"

namespace e2XD::core {
    class Node2D : public Node {
        Vec2 position;
    public:
        Node2D()=default;

        explicit Node2D(Vec2 position);

        [[nodiscard]] const Vec2& getPosition() const;

        void setPosition(const Vec2& position);
    };
} // e2XD

#endif //INC_2XD2_ENGINE_NODE2D_H
