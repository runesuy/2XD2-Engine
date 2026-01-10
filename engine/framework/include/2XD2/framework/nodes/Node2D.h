//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_NODE2D_H
#define INC_2XD2_ENGINE_NODE2D_H
#include "2XD2/framework/nodes/Node.h"
#include "2XD2/core/Transform2D.h"
#include "2XD2/core/Vec2f.h"

namespace e2XD::framework
{
    /**
     * A 2D node in the scene graph.
     * Has 2D transformation properties like position, scale and rotation.
     */
    class Node2D : public Node
    {
        core::Transform2D globalTransform;
        core::Transform2D localTransform;

    public:
        Node2D() = default;

        /**
         *
         * @return the absolute global position of the node in the scene.
         */
        [[nodiscard]] const core::Vec2f& getGlobalPosition() const;

        /**
         * Set the absolute global position of the node in the scene.
         * Children positions will be updated accordingly.
         * @param position
         */
        virtual void setGlobalPosition(const core::Vec2f& position);

        /**
         *
         * @return the local position of the node relative to its parent.
         */
        [[nodiscard]] const core::Vec2f& getLocalPosition() const;

        /**
         * Set the local position of the node relative to its parent.
         * Children positions will be updated accordingly.
         * @param position
         */
        virtual void setLocalPosition(const core::Vec2f& position);

        /**
         *
         * @return the absolute global scale of the node in the scene.
         */
        [[nodiscard]] const core::Vec2f& getGlobalScale() const;

        /**
         * Set the absolute global scale of the node in the scene.
         * Children scales will be updated accordingly.
         * @param scale
         */
        virtual void setGlobalScale(const core::Vec2f& scale);

        /**
         *
         * @return the local scale of the node relative to its parent.
         */
        [[nodiscard]] const core::Vec2f& getLocalScale() const;

        /**
         * Set the local scale of the node relative to its parent.
         * Children scales will be updated accordingly.
         * @param scale
         */
        virtual void setLocalScale(const core::Vec2f& scale);

        /**
         *
         * @return the absolute global rotation of the node in the scene, in degrees.
         */
        [[nodiscard]] double getGlobalRotation() const;

        /**
         * Set the absolute global rotation of the node in the scene, in degrees.
         * Children rotations will be updated accordingly.
         * @param rotation
         */
        virtual void setGlobalRotation(double rotation);

        /**
         *
         * @return the local rotation of the node relative to its parent, in degrees.
         */
        [[nodiscard]] double getLocalRotation() const;

        /**
         * Set the local rotation of the node relative to its parent, in degrees.
         * Children rotations will be updated accordingly.
         * @param rotation
         */
        virtual void setLocalRotation(double rotation);
    };
} // e2XD

#endif //INC_2XD2_ENGINE_NODE2D_H
