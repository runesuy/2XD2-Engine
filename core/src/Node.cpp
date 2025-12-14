//
// Created by runes on 14/12/2025.
//

#include "../include/core/Node.h"

namespace e2XD::core {
    void Node::destroy() {
        markedForDeletion = true;
        for (const auto & node : nodes) {
            node->destroy();
        }
        onDestroy();
    }

    void Node::create() {
        onCreate();
        for (const auto & node : nodes) {
            node->create();
        }
    }

    void Node::render() {
        onRender();
        for (const auto & node : nodes) {
            node->render();
        }
    }

    void Node::update() {
        removeDestroyedSubNodes();
        onUpdate();
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