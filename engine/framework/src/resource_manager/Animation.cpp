// Copyright (c) 2026 Rune Suy and the 2XD2-Engine contributors.
// Licensed under the MIT License.
//

//
// Created by rune-suy on 12/17/25.
//

#include "2XD2/framework/resource_manager/Animation.h"


namespace e2XD::framework
{
    void Animation::addFrame(sf::Texture* texture)
    {
        frames.push_back(texture);
    }

    void Animation::setFrameDuration(double duration)
    {
        _frameDuration = duration;
    }

    void Animation::setLooping(bool looping)
    {
        _isLooping = looping;
    }

    Animation::Animation(const std::initializer_list<const sf::Texture*>& frameList, double frameDuration,
                         bool isLooping) :
        frames(frameList), _frameDuration(frameDuration), _isLooping(isLooping)
    {
    }

    Animation::Animation(const std::vector<const sf::Texture*>& frameList, double frameDuration, bool isLooping) :
        frames(frameList), _frameDuration(frameDuration), _isLooping(isLooping)
    {
    }

    const std::vector<const sf::Texture*>& Animation::getFrames() const
    {
        return frames;
    }

    double Animation::getFrameDuration() const
    {
        return _frameDuration;
    }

    bool Animation::isLooping() const
    {
        return _isLooping;
    }
} // framework
// e2XD
