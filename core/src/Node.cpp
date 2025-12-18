//
// Created by runes on 14/12/2025.
//

#include "2XD2/core/Node.h"

namespace e2XD::core {
    void Node::destroy() {
        markedForDeletion = true;
        for (const auto & node : nodes) {
            node->destroy();
        }
        onDestroy();
    }

    void Node::create() {
        for (const auto & node : nodes) {
            node->create();
        }
        onCreate();
    }
    void Node::update() {
        removeDestroyedSubNodes();
        for (const auto & node : nodes) {
            node->update();
        }
        onUpdate();
    }

    void Node::draw() {
        for (const auto & node : nodes) {
            node->draw();
        }
        _internal_onDraw();
        onDraw();
    }

    void Node::removeDestroyedSubNodes() {
        for (auto it = nodes.begin(); it != nodes.end(); ) {
            if ((*it)->markedForDeletion) {
                (*it)->destroy();
                it = nodes.erase(it);
            } else {
                ++it;
            }
        }
    }
} // e2XD