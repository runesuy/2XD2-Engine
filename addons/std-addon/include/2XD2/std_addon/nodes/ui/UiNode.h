//
// Created by rune-suy on 1/27/26.
//

#ifndef FLATLAND_UINODE_H
#define FLATLAND_UINODE_H
#include "2XD2/framework/nodes/Drawable2D.h"


namespace e2XD::std_addon
    {
        class UiNode : public framework::Drawable2D
        {
            core::Vec2f _size{100.0f, 100.0f};
        public:
            UiNode();
            ~UiNode() override = default;

            void setSize(const core::Vec2f& size);

            [[nodiscard]] const core::Vec2f& getSize() const;

        protected:
            virtual void _onLayoutChanged(){};

            virtual void _internal_onLayoutChange(){};

            void _notification(int what) override;
        };
    } // std_addon
// e2XD

#endif //FLATLAND_UINODE_H