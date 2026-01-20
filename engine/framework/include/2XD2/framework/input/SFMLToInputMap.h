// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/15/25.
//

#ifndef INC_2XD2_ENGINE_SFMLTOINPUTMAP_H
#define INC_2XD2_ENGINE_SFMLTOINPUTMAP_H

#include <SFML/Window/Event.hpp>
#include "Key.h"
#include "unordered_map"

namespace e2XD::framework::internal::input
{
    /**
     * Map used by SFMLInputHandler to convert SFML key codes to framework key codes
     */
    inline std::unordered_map<sf::Keyboard::Key, Key> keyboardMap{
        {sf::Keyboard::A, Key::A},
        {sf::Keyboard::B, Key::B},
        {sf::Keyboard::C, Key::C},
        {sf::Keyboard::D, Key::D},
        {sf::Keyboard::E, Key::E},
        {sf::Keyboard::F, Key::F},
        {sf::Keyboard::G, Key::G},
        {sf::Keyboard::H, Key::H},
        {sf::Keyboard::I, Key::I},
        {sf::Keyboard::J, Key::J},
        {sf::Keyboard::K, Key::K},
        {sf::Keyboard::L, Key::L},
        {sf::Keyboard::M, Key::M},
        {sf::Keyboard::N, Key::N},
        {sf::Keyboard::O, Key::O},
        {sf::Keyboard::P, Key::P},
        {sf::Keyboard::Q, Key::Q},
        {sf::Keyboard::R, Key::R},
        {sf::Keyboard::S, Key::S},
        {sf::Keyboard::T, Key::T},
        {sf::Keyboard::U, Key::U},
        {sf::Keyboard::V, Key::V},
        {sf::Keyboard::W, Key::W},
        {sf::Keyboard::X, Key::X},
        {sf::Keyboard::Y, Key::Y},
        {sf::Keyboard::Z, Key::Z},
        {sf::Keyboard::LShift, Key::L_SHIFT},
        {sf::Keyboard::RShift, Key::R_SHIFT},
    };

    inline std::unordered_map<sf::Mouse::Button, MouseButton> mouseButtonMap{
        {sf::Mouse::Left, MouseButton::LEFT},
        {sf::Mouse::Right, MouseButton::RIGHT}
    };
}
#endif //INC_2XD2_ENGINE_SFMLTOINPUTMAP_H
