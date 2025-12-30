//
// Created by runes on 14/12/2025.
//

#include "2XD2/core/Node.h"

namespace e2XD::framework
{
    void Node::destroy()
    {
        markedForDeletion = true;
        for (const auto& node : nodes)
        {
            node->destroy();
        }
        _internal_onDestroy();
        onDestroy();
    }

    void Node::create()
    {
        _internal_onCreate();
        onCreate();
    }

    void Node::update()
    {
        removeDestroyedSubNodes();
        for (const auto& node : nodes)
        {
            node->update();
        }
        _internal_onUpdate();
        onUpdate();
    }

    void Node::_internal_onDraw()
    {
        for (const auto& node : nodes)
        {
            node->draw();
        }
    }

    void Node::removeDestroyedSubNodes()
    {
        for (auto it = nodes.begin(); it != nodes.end();)
        {
            if ((*it)->markedForDeletion)
            {
                (*it)->destroy();
                it = nodes.erase(it);
            }
            else
            {
                ++it;
            }
        }
    }
} // e2XD