// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by copilot on 1/24/26.
//

#ifndef INC_2XD2_ENGINE_CONTROL_H
#define INC_2XD2_ENGINE_CONTROL_H

#include "2XD2/framework/nodes/Node2D.h"
#include "2XD2/core/Vec2f.h"

namespace e2XD::std_addon
{
    /**
     * Base class for UI elements.
     * Control nodes provide size information and anchor/margin features
     * for building user interfaces.
     */
    class Control : public framework::Node2D
    {
    protected:
        core::Vec2f _size{0.0f, 0.0f};
        core::Vec2f _minSize{0.0f, 0.0f};

    public:
        Control() = default;

        /**
         * Get the size of the control.
         * @return The size as a Vec2f (width, height).
         */
        [[nodiscard]] const core::Vec2f& getSize() const { return _size; }

        /**
         * Set the size of the control.
         * @param size The new size (width, height).
         */
        virtual void setSize(const core::Vec2f& size);

        /**
         * Get the width of the control.
         * @return The width.
         */
        [[nodiscard]] float getWidth() const { return _size.x; }

        /**
         * Set the width of the control.
         * @param width The new width.
         */
        virtual void setWidth(float width);

        /**
         * Get the height of the control.
         * @return The height.
         */
        [[nodiscard]] float getHeight() const { return _size.y; }

        /**
         * Set the height of the control.
         * @param height The new height.
         */
        virtual void setHeight(float height);

        /**
         * Get the minimum size of the control.
         * @return The minimum size as a Vec2f (width, height).
         */
        [[nodiscard]] const core::Vec2f& getMinSize() const { return _minSize; }

        /**
         * Set the minimum size of the control.
         * @param minSize The minimum size (width, height).
         */
        virtual void setMinSize(const core::Vec2f& minSize);

        /**
         * Get the computed minimum size including children requirements.
         * @return The combined minimum size.
         */
        [[nodiscard]] virtual core::Vec2f getCombinedMinSize() const;
    };
} // std_addon
// e2XD

#endif //INC_2XD2_ENGINE_CONTROL_H
