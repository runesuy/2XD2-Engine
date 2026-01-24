// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by copilot on 1/24/26.
//

#include "../include/2XD2/std_addon/nodes/Control.h"

namespace e2XD::std_addon
{
    void Control::setSize(const core::Vec2f& size)
    {
        _size.x = std::max(size.x, _minSize.x);
        _size.y = std::max(size.y, _minSize.y);
    }

    void Control::setWidth(float width)
    {
        _size.x = std::max(width, _minSize.x);
    }

    void Control::setHeight(float height)
    {
        _size.y = std::max(height, _minSize.y);
    }

    void Control::setMinSize(const core::Vec2f& minSize)
    {
        _minSize = minSize;
        // Ensure current size respects the new minimum
        if (_size.x < _minSize.x) _size.x = _minSize.x;
        if (_size.y < _minSize.y) _size.y = _minSize.y;
    }

    core::Vec2f Control::getCombinedMinSize() const
    {
        return _minSize;
    }
} // std_addon
// e2XD
