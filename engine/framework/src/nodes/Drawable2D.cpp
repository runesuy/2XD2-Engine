// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 1/26/26.
//

#include "2XD2/framework/nodes/Drawable2D.h"

#include "2XD2/framework/drawing/Renderer.h"
#include "2XD2/framework/nodes/Notifications.hpp"


namespace e2XD::framework
{
    void Drawable2D::_internal_onCreate()
    {
        Renderer::registerDrawable(this);
        Node2D::_internal_onCreate();
    }

    void Drawable2D::setVisible(const bool visible)
    {
        if (this->isVisible() == visible)
        {
            Drawable::setVisible(visible);
            return;
        }
        Drawable::setVisible(visible);
        if (visible) _sendNotification(NOTIFICATION_VISIBILITY_TRUE);
        else _sendNotification(NOTIFICATION_VISIBILITY_FALSE);
    }

    void Drawable2D::_notification(const int what)
    {
        switch (what)
        {
        case NOTIFICATION_VISIBILITY_TRUE:
            setVisible(true);
            break;
        case NOTIFICATION_VISIBILITY_FALSE:
            setVisible(false);
            break;
        default:
            break;
        }
        Node2D::_notification(what);
    }

    void Drawable2D::addSubNode(std::unique_ptr<Node> node)
    {
        node->_notification(this->isVisible() ? NOTIFICATION_VISIBILITY_TRUE : NOTIFICATION_VISIBILITY_FALSE);
        Node2D::addSubNode(std::move(node));
    }
} // framework
// e2XD
