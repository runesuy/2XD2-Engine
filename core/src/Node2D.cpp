//
// Created by runes on 14/12/2025.
//

#include "2XD2/core/Node2D.h"

namespace e2XD::core {
    const Vec2f &Node2D::getGlobalPosition() const {
        return globalTransform.getPosition();
    }

    void Node2D::setGlobalPosition(const Vec2f &position) {
        auto positionDiff = position - globalTransform.getPosition();
        globalTransform.setPosition(position);
        localTransform.setPosition(localTransform.getPosition() + positionDiff);

        // Update children's global positions
        for (auto &childNode : nodes) {
            if (auto childNode2D = dynamic_cast<Node2D*>(childNode.get())) {
                auto childGlobalPos = childNode2D->getGlobalPosition();
                childNode2D->setGlobalPosition(childGlobalPos + positionDiff);
            }
        }
    }

    const Vec2f &Node2D::getLocalPosition() const {
        return localTransform.getPosition();
    }

    void Node2D::setLocalPosition(const Vec2f &position) {
        auto positionDiff = position - localTransform.getPosition();
        localTransform.setPosition(position);
        globalTransform.setPosition(globalTransform.getPosition() + positionDiff);

        // Update children's local positions
        for (auto &childNode : nodes) {
            if (auto childNode2D = dynamic_cast<Node2D*>(childNode.get())) {
                auto childLocalPos = childNode2D->getLocalPosition();
                childNode2D->setLocalPosition(childLocalPos + positionDiff);
            }
        }
    }

    const Vec2f &Node2D::getGlobalScale() const {
        return globalTransform.getScale();
    }

    void Node2D::setGlobalScale(const Vec2f &scale) {
        auto scaleDiff = scale / globalTransform.getScale();
        this->globalTransform.setScale(scale);
        this->localTransform.setScale(localTransform.getScale() * scaleDiff);

        // Update children's global scales
        for (auto &childNode : nodes) {
            if (auto childNode2D = dynamic_cast<Node2D*>(childNode.get())) {
                auto childGlobalScale = childNode2D->getGlobalScale();
                childNode2D->setGlobalScale(childGlobalScale * scaleDiff);
            }
        }
    }

    const Vec2f &Node2D::getLocalScale() const {
        return localTransform.getScale();
    }

    void Node2D::setLocalScale(const Vec2f &scale) {
        auto scaleDiff = scale / localTransform.getScale();
        this->localTransform.setScale(scale);
        this->globalTransform.setScale(globalTransform.getScale() * scaleDiff);

        // Update children's local scales
        for (auto &childNode : nodes) {
            if (auto childNode2D = dynamic_cast<Node2D*>(childNode.get())) {
                auto childLocalScale = childNode2D->getLocalScale();
                childNode2D->setLocalScale(childLocalScale * scaleDiff);
            }
        }
    }

    double Node2D::getGlobalRotation() const {
        return globalTransform.getRotation();
    }

    void Node2D::setGlobalRotation(double rotation) {
        double rotationDiff = rotation - globalTransform.getRotation();
        this->globalTransform.setRotation(rotation);
        this->localTransform.setRotation(localTransform.getRotation() + rotationDiff);

        // Update children's global rotations
        for (auto &childNode : nodes) {
            if (auto childNode2D = dynamic_cast<Node2D*>(childNode.get()))
            {
                double childGlobalRot = childNode2D->getGlobalRotation();
                childNode2D->setGlobalRotation(childGlobalRot + rotationDiff);
            }
        }
    }

    double Node2D::getLocalRotation() const {
        return localTransform.getRotation();
    }

    void Node2D::setLocalRotation(double rotation) {
        double rotationDiff = rotation - localTransform.getRotation();
        this->localTransform.setRotation(rotation);
        this->globalTransform.setRotation(globalTransform.getRotation() + rotationDiff);

        // Update children's local rotations
        for (auto &childNode : nodes) {
            if (auto childNode2D = dynamic_cast<Node2D*>(childNode.get())) {
                double childLocalRot = childNode2D->getLocalRotation();
                childNode2D->setLocalRotation(childLocalRot + rotationDiff);
            }
        }
    }
}