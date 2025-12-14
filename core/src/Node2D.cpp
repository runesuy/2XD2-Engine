//
// Created by runes on 14/12/2025.
//

#include "../include/core/Node2D.h"

namespace e2XD::core {
    Node2D::Node2D(const Vec2 position) : position(position) {}

    const Vec2 &Node2D::getPosition() const {
        return position;
    }

    void Node2D::setPosition(const Vec2 &position) {
        this->position = position;
    }
}