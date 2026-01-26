//
// Created by rune-suy on 1/25/26.
//

#ifndef FLATLAND_DRAWFRAME_H
#define FLATLAND_DRAWFRAME_H
#include "2XD2/core/Vec2.hpp"
#include "2XD2/framework/nodes/Node.h"
#include "2XD2/framework/signals/Signal.h"


namespace e2XD::framework
{
    class Camera;

    class DrawTarget : public Node
    {
        core::Vec2<unsigned int> size;

        const Camera* activeCamera = nullptr;

    public:
        Signal<> onSizeChanged;
        Signal<> onActiveCameraChanged;

        DrawTarget() = default;
        ~DrawTarget() override = default;

        void setSize(unsigned int width, unsigned int height);

        [[nodiscard]] const core::Vec2<unsigned int>& getSize() const;

        void setActiveCamera(const Camera* camera);

        [[nodiscard]] const Camera* getActiveCamera() const;

    protected:
        void _internal_onCreate() override;
    };
}

#endif //FLATLAND_DRAWFRAME_H
