//
// Created by rune-suy on 1/27/26.
//

#include "2XD2/std_addon/nodes/ui/UiNode.h"

#include "2XD2/framework/nodes/Notifications.hpp"


namespace e2XD::std_addon
{
    UiNode::UiNode()
    {
        renderLayer = RenderLayer::UI;
    }

    void UiNode::setSize(const core::Vec2f& size)
    {
        _size = size;
    }

    const core::Vec2f& UiNode::getSize() const
    {
        return _size;
    }

    void UiNode::_notification(int what)
    {
        Drawable2D::_notification(what);
        if (what == NOTIFICATION_LAYOUT_CHANGED)
        {
            _internal_onLayoutChange();
            _onLayoutChanged();
        }
    }
} // std_addon
// e2XD
