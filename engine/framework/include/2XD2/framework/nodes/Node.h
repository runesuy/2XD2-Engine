//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_ENTITY_H
#define INC_2XD2_ENGINE_ENTITY_H
#include <list>
#include <memory>

#include "Node.h"
#include<type_traits>

#include "2XD2/framework/drawing/Renderable.h"


namespace e2XD::framework
{
    class Node;
    template <typename T>
    concept IsNode = std::is_base_of_v<Node, T>;

    /**
     * A node in the scene graph.
     * Is renderable by the Renderer.
     */
    class Node : public Renderable
    {
        bool markedForDeletion = false;
        std::list<std::unique_ptr<Node>> nodes;

        /**
         * Remove all sub-nodes that are marked for deletion.
         */
        void removeDestroyedSubNodes();

    protected:
        /**
         * Placeholder for user-defined update logic.
         * This method is called during the update phase of the node.
         */
        virtual void onUpdate()
        {
        };

        /**
         * Placeholder for internal update logic.
         * This method is called during the update phase of the node.
         */
        virtual void _internal_onUpdate()
        {
        };

        /**
         * Placeholder for user-defined creation logic.
         * This method is called when the node is added to the scene.
         */
        virtual void onCreate()
        {
        };

        /**
         * Placeholder for internal creation logic.
         * This method is called when the node is created.
         */
        virtual void _internal_onCreate()
        {
        };

        /**
         * Placeholder for user-defined destruction logic.
         * This method is called when the node is destroyed.
         */
        virtual void onDestroy()
        {
        };

        /**
         * Placeholder for internal destruction logic.
         * This method is called when the node is destroyed.
         */
        virtual void _internal_onDestroy()
        {
        };

        void _internal_onDraw() override;

    public:
        friend class CORE_Node;
        friend class Node2D;

        /**
         * Creat a new empty node.
         */
        Node() = default;
        ~Node() override = default;

        /**
         * Update the node and its sub-nodes.
         */
        void update();

        /**
         * Create the node and its sub-nodes.
         */
        void create();

        /**
         * Destroy the node and its sub-nodes.
         */
        void destroy();

        /**
         * Create and add a sub-node of the specified type.
         * @tparam EntityType
         * @return a pointer to the created sub-node.
         */
        template <IsNode EntityType>
        EntityType* createSubNode();

        /**
         * Add a sub-node to this node.
         * @param node
         */
        virtual void addSubNode(std::unique_ptr<Node> node);

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

        [[nodiscard]] std::list<Node*> getSubNodes();

        [[nodiscard]] std::list<const Node*> getSubNodes() const;
    };

    template <IsNode EntityType>
    EntityType* Node::createSubNode()
    {
        auto node = std::make_unique<EntityType>();
        auto ptr = node.get();
        addSubNode(std::move(node));
        return ptr;
    }

    inline void Node::addSubNode(std::unique_ptr<Node> node)
    {
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
