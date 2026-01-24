// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by copilot on 1/24/26.
//

#include "../include/2XD2/std_addon/nodes/MarginContainer.h"

namespace e2XD::std_addon
{
    void MarginContainer::setMargins(const Margins& margins)
    {
        _margins = margins;
        updateChildrenLayout();
    }

    void MarginContainer::setMargins(float margin)
    {
        _margins.left = margin;
        _margins.right = margin;
        _margins.top = margin;
        _margins.bottom = margin;
        updateChildrenLayout();
    }

    void MarginContainer::setMargins(float horizontal, float vertical)
    {
        _margins.left = horizontal;
        _margins.right = horizontal;
        _margins.top = vertical;
        _margins.bottom = vertical;
        updateChildrenLayout();
    }

    void MarginContainer::setMarginLeft(float margin)
    {
        _margins.left = margin;
        updateChildrenLayout();
    }

    void MarginContainer::setMarginRight(float margin)
    {
        _margins.right = margin;
        updateChildrenLayout();
    }

    void MarginContainer::setMarginTop(float margin)
    {
        _margins.top = margin;
        updateChildrenLayout();
    }

    void MarginContainer::setMarginBottom(float margin)
    {
        _margins.bottom = margin;
        updateChildrenLayout();
    }

    float MarginContainer::getInnerWidth() const
    {
        const float inner = _size.x - _margins.left - _margins.right;
        return std::max(0.0f, inner);
    }

    float MarginContainer::getInnerHeight() const
    {
        const float inner = _size.y - _margins.top - _margins.bottom;
        return std::max(0.0f, inner);
    }

    core::Vec2f MarginContainer::getInnerSize() const
    {
        return {getInnerWidth(), getInnerHeight()};
    }

    core::Vec2f MarginContainer::getCombinedMinSize() const
    {
        // Minimum size is margins plus the base minimum size
        return {
            _minSize.x + _margins.left + _margins.right,
            _minSize.y + _margins.top + _margins.bottom
        };
    }

    void MarginContainer::updateChildrenLayout()
    {
        // Calculate the offset for children based on margins
        // Children are positioned relative to the top-left of the content area
        const core::Vec2f contentOffset{_margins.left, _margins.top};

        // Update all child Node2D positions
        for (auto* child : getSubNodes())
        {
            if (auto* child2D = dynamic_cast<framework::Node2D*>(child))
            {
                child2D->setLocalPosition(contentOffset);
            }
        }
    }

    void MarginContainer::_internal_onCreate()
    {
        Control::_internal_onCreate();
        updateChildrenLayout();
    }
} // std_addon
// e2XD
