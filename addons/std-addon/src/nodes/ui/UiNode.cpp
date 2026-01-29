//
// Created by rune-suy on 1/27/26.
//

#include "2XD2/std_addon/nodes/ui/UiNode.h"


namespace e2XD::std_addon
{
    void UiNode::setSize(const core::Vec2f& size)
    {
        _size = size;
    }

    const core::Vec2f& UiNode::getSize() const
    {
        return _size;
    }
} // std_addon
// e2XD
