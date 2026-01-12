//
// Created by runes on 14/12/2025.
//

#include "2XD2/framework/nodes/Node.h"

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
        _isCreated = true;
        onCreate();
        for (const auto& node : nodes)
        {
            node->create();
        }
    }

    void Node::update()
    {
        removeDestroyedSubNodes();
        if (_paused && processMode != ProcessMode::ALWAYS_RUNNING) return;
        if (processMode == ProcessMode::ALWAYS_INHERIT && _parent != nullptr)
        {
            if (_parent->_paused)
            {
                return;
            }
        }
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

    std::list<Node*> Node::getSubNodes()
    {
        std::list<Node*> nodesL;
        for (const auto& node : this->nodes)
        {
            nodesL.push_back(node.get());
        }
        return nodesL;
    }

    std::list<const Node*> Node::getSubNodes() const
    {
        std::list<const Node*> nodesL;
        for (const auto& node : this->nodes)
        {
            nodesL.push_back(node.get());
        }
        return nodesL;
    }

    void Node::setRenderLayer(RenderLayer renderLayer)
    {
        Renderable::setRenderLayer(renderLayer);
        for (const auto& node : nodes)
        {
            node->setRenderLayer(renderLayer);
        }
    }

    const Node* Node::getParent() const
    {
        return _parent;
    }

    Node* Node::getParent()
    {
        return _parent;
    }

    void Node::setPaused(bool paused)
    {
        _paused = paused;
        for (const auto& node : nodes)
        {
            if (node->processMode != ProcessMode::STUBBORN)
                node->setPaused(paused);
        }
    }
} // e2XD
