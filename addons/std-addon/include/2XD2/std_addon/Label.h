//
// Created by rune-suy on 1/10/26.
//

#ifndef INC_2XD2_ENGINE_LABEL_H
#define INC_2XD2_ENGINE_LABEL_H
#include <string>
#include <SFML/Graphics/Text.hpp>

#include "2XD2/framework/nodes/Node2D.h"


namespace e2XD::std_addon
{
    /**
     * A text label node.
     */
    class Label : public framework::Node2D
    {
        sf::Text _text;
    public:
        Label();

        void setText(const std::string &text);

        void setFontSize(unsigned int size);

    protected:
        void _internal_onDraw() override;
    };
} // std_addon
// e2XD

#endif //INC_2XD2_ENGINE_LABEL_H
