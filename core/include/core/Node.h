//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_ENTITY_H
#define INC_2XD2_ENGINE_ENTITY_H
#include <list>
#include <memory>

#include "Node.h"
#include<type_traits>

namespace e2XD::core {
    class Node;
    template <typename T>
    concept IsNode = std::is_base_of_v<Node, T>;

    class Node {
        bool markedForDeletion = false;
        std::list<std::unique_ptr<Node>> nodes;

        void removeDestroyedSubNodes();
    protected:
        virtual void onUpdate(){};

        virtual void onRender(){};

        virtual void onCreate(){};

        virtual void onDestroy(){};

    public:
        friend class CORE_Node;

        Node()=default;

        virtual ~Node() = default;

        void update();

        void render();

        void create();

        void destroy();

        template <IsNode EntityType>
        void createSubNode();

        void addSubNode(std::unique_ptr<Node> node);
    };

    template<IsNode EntityType>
    void Node::createSubNode() {
        auto node = std::make_unique<EntityType>();
        node->create();
        nodes.push_back(std::move(node));
    }

    inline void Node::addSubNode(std::unique_ptr<Node> node) {
        node->create();
        nodes.push_back(std::move(node));
    }
} // e2XD

#endif //INC_2XD2_ENGINE_ENTITY_H
