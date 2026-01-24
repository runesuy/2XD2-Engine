// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by runes on 14/12/2025.
//

#ifndef INC_2XD2_ENGINE_ENTITY_H
#define INC_2XD2_ENGINE_ENTITY_H
#include <list>
#include <memory>

#include "Node.h"
#include<type_traits>

#include "ProcessMode.h"
#include "2XD2/framework/drawing/Renderable.h"


namespace e2XD::framework
{
    class Scene;
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
        bool _isCreated = false;
        bool _paused = false;
        bool _isDestroyed = false;

        Node* _parent=nullptr;

        friend class Scene;
        Scene* _scene=nullptr;

        std::list<std::unique_ptr<Node>> nodes;

        /**
         * Remove all sub-nodes that are marked for deletion.
         */
        void removeDestroyedSubNodes();

    protected:
        ProcessMode processMode = ProcessMode::DEFAULT;

        /**
         * Placeholder for user-defined update logic.
         * This method is called during the update phase of the node.
         */
        virtual void onUpdate(double deltaTime)
        {
        };

        /**
         * Placeholder for internal update logic.
         * This method is called during the update phase of the node.
         */
        virtual void _internal_onUpdate(double deltaTime)
        {
        };

        /**
         * Placeholder for user-defined physics update logic.
         * This method is called during the physics update phase of the node.
         * Called a fixed number of times per second.
         */
        virtual void onPhysicsUpdate(double deltaTime)
        {
        };

        /**
         * Placeholder for internal physics update logic.
         * This method is called during the physics update phase of the node.
         * Called a fixed number of times per second.
         */
        virtual void _internal_onPhysicsUpdate(double deltaTime)
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
        ~Node() override;

        /**
         * Update the node and its sub-nodes.
         */
        void update(double deltaTime);

        /**
         * Call the physics update on the node and its sub-nodes.
         * @param deltaTime
         */
        void physicsUpdate(double deltaTime);

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
        template <IsNode EntityType, typename... Args>
        EntityType* createSubNode(Args&& ...args);

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

        /**
         * Get a list of all sub-nodes.
         * @return A list of pointers to all sub-nodes.
         */
        [[nodiscard]] std::list<Node*> getSubNodes();

        /**
         * Get a list of all sub-nodes.
         * @return A list of pointers to all sub-nodes.
         */
        [[nodiscard]] std::list<const Node*> getSubNodes() const;

        void setRenderLayer(RenderLayer renderLayer) override;

        /**
         *
         * @return the parent node, or nullptr if this node has no parent.
         */
        [[nodiscard]] const Node* getParent() const;

        /**
         *
         * @return the parent node, or nullptr if this node has no parent.
         */
        [[nodiscard]] Node* getParent();

        /**
         *
         * @return the scene this node belongs to, or nullptr if this node is not part of a scene.
         */
        [[nodiscard]] const Scene* getScene() const;

        /**
         *
         * @return the scene this node belongs to, or nullptr if this node is not part of a scene.
         */
        [[nodiscard]] Scene* getScene();

        void setPaused(bool paused);
    };

    template <IsNode EntityType, typename... Args>
    EntityType* Node::createSubNode(Args&&...args)
    {
        auto node = std::make_unique<EntityType>(args...);
        auto ptr = node.get();
        addSubNode(std::move(node));
        return ptr;
    }

    inline void Node::addSubNode(std::unique_ptr<Node> node)
    {
        node->_parent = this;
        nodes.push_back(std::move(node));
        if (_isCreated)
        {
            nodes.back()->create();
        }
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
