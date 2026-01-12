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

    void Animation::setFrameDuration(float duration)
    {
        _frameDuration = duration;
    }

    void Animation::setLooping(bool looping)
    {
        _isLooping = looping;
    }

    Animation::Animation(const std::initializer_list<const sf::Texture*>& frameList, float frameDuration,
                         bool isLooping) :
        frames(frameList), _frameDuration(frameDuration), _isLooping(isLooping)
    {
    }

    Animation::Animation(const std::vector<const sf::Texture*>& frameList, float frameDuration, bool isLooping) :
        frames(frameList), _frameDuration(frameDuration), _isLooping(isLooping)
    {
    }

    const std::vector<const sf::Texture*>& Animation::getFrames() const
    {
        return frames;
    }

    float Animation::getFrameDuration() const
    {
        return _frameDuration;
    }

    bool Animation::isLooping() const
    {
        return _isLooping;
    }
} // framework
// e2XD
