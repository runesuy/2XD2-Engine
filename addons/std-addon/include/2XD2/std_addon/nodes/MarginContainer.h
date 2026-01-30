// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by copilot on 1/24/26.
//

#ifndef INC_2XD2_ENGINE_MARGINCONTAINER_H
#define INC_2XD2_ENGINE_MARGINCONTAINER_H

#include "Control.h"

namespace e2XD::std_addon
{
    /**
     * A container that adds margin around its children.
     * Similar to Godot's MarginContainer, it adds configurable
     * margin offsets (left, right, top, bottom) to all children.
     * Children are positioned within the margin boundaries.
     */
    class MarginContainer : public Control
    {
    public:
        /**
         * Struct to hold margin values for each side.
         */
        struct Margins
        {
            float left = 0.0f;
            float right = 0.0f;
            float top = 0.0f;
            float bottom = 0.0f;
        };

    private:
        Margins _margins;

    public:
        MarginContainer() = default;

        /**
         * Set all margins at once.
         * @param margins The margin values.
         */
        void setMargins(const Margins& margins);

        /**
         * Set all margins to the same value.
         * @param margin The margin value for all sides.
         */
        void setMargins(float margin);

        /**
         * Set horizontal and vertical margins.
         * @param horizontal The margin for left and right.
         * @param vertical The margin for top and bottom.
         */
        void setMargins(float horizontal, float vertical);

        /**
         * Get the current margins.
         * @return The margin values.
         */
        [[nodiscard]] const Margins& getMargins() const { return _margins; }

        /**
         * Set the left margin.
         * @param margin The left margin value.
         */
        void setMarginLeft(float margin);

        /**
         * Get the left margin.
         * @return The left margin value.
         */
        [[nodiscard]] float getMarginLeft() const { return _margins.left; }

        /**
         * Set the right margin.
         * @param margin The right margin value.
         */
        void setMarginRight(float margin);

        /**
         * Get the right margin.
         * @return The right margin value.
         */
        [[nodiscard]] float getMarginRight() const { return _margins.right; }

        /**
         * Set the top margin.
         * @param margin The top margin value.
         */
        void setMarginTop(float margin);

        /**
         * Get the top margin.
         * @return The top margin value.
         */
        [[nodiscard]] float getMarginTop() const { return _margins.top; }

        /**
         * Set the bottom margin.
         * @param margin The bottom margin value.
         */
        void setMarginBottom(float margin);

        /**
         * Get the bottom margin.
         * @return The bottom margin value.
         */
        [[nodiscard]] float getMarginBottom() const { return _margins.bottom; }

        /**
         * Get the inner width (size minus horizontal margins).
         * @return The inner width available for children.
         */
        [[nodiscard]] float getInnerWidth() const;

        /**
         * Get the inner height (size minus vertical margins).
         * @return The inner height available for children.
         */
        [[nodiscard]] float getInnerHeight() const;

        /**
         * Get the inner size (size minus all margins).
         * @return The inner size available for children.
         */
        [[nodiscard]] core::Vec2f getInnerSize() const;

        /**
         * Get the computed minimum size including margins and children requirements.
         * @return The combined minimum size.
         */
        [[nodiscard]] core::Vec2f getCombinedMinSize() const override;

    protected:
        /**
         * Update children positions based on margins.
         * Called after margins or size changes.
         */
        void updateChildrenLayout();

        void _internal_onCreate() override;
    };
} // std_addon
// e2XD

#endif //INC_2XD2_ENGINE_MARGINCONTAINER_H
