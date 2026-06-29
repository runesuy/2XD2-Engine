//
// Created by rune-suy on 1/30/26.
//

#ifndef FLATLAND_UICONTAINER_H
#define FLATLAND_UICONTAINER_H
#include "UiNode.h"

namespace e2XD::std_addon
{
    class UiContainer : public UiNode
    {
    public:
        UiContainer() = default;
        ~UiContainer() override = default;

    protected:
       void _internal_onLayoutChange() override;
    };
}

#endif //FLATLAND_UICONTAINER_H
