//
// Created by rune-suy on 12/15/25.
//

#ifndef INC_2XD2_ENGINE_SFMLTOINPUTMAP_H
#define INC_2XD2_ENGINE_SFMLTOINPUTMAP_H

#include <SFML/Window/Event.hpp>
#include "Key.h"
#include "unordered_map"

namespace e2XD::framework::input
{
    inline std::unordered_map<sf::Keyboard::Key, Key> keyboardMap{
        {sf::Keyboard::A, Key::A},
        {sf::Keyboard::B, Key::B},
        {sf::Keyboard::C, Key::C},
        {sf::Keyboard::D, Key::D},
    };

    inline std::unordered_map<sf::Mouse::Button, MouseButton> mouseButtonMap{
        {sf::Mouse::Left, MouseButton::LEFT},
        {sf::Mouse::Right, MouseButton::RIGHT}
    };



}
#endif //INC_2XD2_ENGINE_SFMLTOINPUTMAP_H
