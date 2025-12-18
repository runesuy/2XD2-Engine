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

        virtual void _internal_onUpdate(){};

        virtual void onCreate(){};

        virtual void _internal_onCreate(){};

        virtual void onDestroy(){};

        virtual void _internal_onDestroy(){};

        virtual void onDraw(){};

        virtual void _internal_onDraw(){};

    public:
        friend class CORE_Node;
        friend class Node2D;

        Node()=default;

        virtual ~Node() = default;

        void update();

        void create();

        void destroy();

        void draw();

        template <IsNode EntityType>
        EntityType* createSubNode();

        void addSubNode(std::unique_ptr<Node> node);

        /**
         * Get the first sub-node of the specified type.
         * @tparam EntityType
         * @return A pointer to the sub-node of the specified type, or nullptr if not found.
         */
        template <IsNode EntityType>
        [[nodiscard]] const EntityType* getSubNode() const;

        /**
         * Get a list of all sub-nodes of the specified type.
         * @tparam EntityType
         * @return A list of pointers to the sub-nodes of the specified type.
         */
        template <IsNode EntityType>
        [[nodiscard]] std::list<const EntityType*> getSubNodes() const;

        /**
         * Get the first sub-node of the specified type.
         * @tparam EntityType
         * @return A pointer to the sub-node of the specified type, or nullptr if not found.
         */
        template <IsNode EntityType>
        [[nodiscard]] EntityType* getSubNode();

        /**
         * Get a list of all sub-nodes of the specified type.
         * @tparam EntityType
         * @return A list of pointers to the sub-nodes of the specified type.
         */
        template <IsNode EntityType>
        [[nodiscard]] std::list<EntityType*> getSubNodes();
    };

    template<IsNode EntityType>
    EntityType* Node::createSubNode() {
        auto node = std::make_unique<EntityType>();
        auto ptr = node.get();
        addSubNode(std::move(node));
        return ptr;
    }

    inline void Node::addSubNode(std::unique_ptr<Node> node) {
        node->create();
        nodes.push_back(std::move(node));
    }

    template <IsNode EntityType>
    const EntityType* Node::getSubNode() const
    {
        // Search for the first sub-node of the specified type
        for (const auto& node : nodes)
        {
            if (auto castedNode = dynamic_cast<EntityType*>(node.get()))
            {
                return castedNode;
            }
        }
        return nullptr; // Return nullptr if no matching sub-node is found
    }

    template <IsNode EntityType>
    std::list<const EntityType*> Node::getSubNodes() const
    {
        std::list<const EntityType*> result;
        // Search for all sub-nodes of the specified type
        for (const auto& node : nodes)
        {
            if (auto castedNode = dynamic_cast<EntityType*>(node.get()))
            {
                result.push_back(castedNode);
            }
        }
        return result;
    }

    template <IsNode EntityType>
    EntityType* Node::getSubNode()
    {
        // Search for the first sub-node of the specified type
        for (const auto& node : nodes)
        {
            if (auto castedNode = dynamic_cast<EntityType*>(node.get()))
            {
                return castedNode;
            }
        }
        return nullptr; // Return nullptr if no matching sub-node is found
    }

    template <IsNode EntityType>
        std::list<EntityType*> Node::getSubNodes()
    {
        std::list<EntityType*> result;
        // Search for all sub-nodes of the specified type
        for (const auto& node : nodes)
        {
            if (auto castedNode = dynamic_cast<EntityType*>(node.get()))
            {
                result.push_back(castedNode);
            }
        }
        return result;
    }

} // e2XD

#endif //INC_2XD2_ENGINE_ENTITY_H
