//
// Created by rune-suy on 12/17/25.
//

#include "2XD2/std_addon/AnimatedSprite2D.h"

#include "2XD2/framework/Time.h"


namespace e2XD::std_addon
{
    void AnimatedSprite2D::setAnimations(const std::unordered_map<std::string, framework::Animation>& newAnimations)
    {
        animations = &newAnimations;
        _currentFrameIndex = 0;
        _frameTimer = 0.0f;
    }

    void AnimatedSprite2D::playAnimation(const std::string& name, const bool continueAtCurrentFrame)
    {
        if (name == _currentAnimationName) return;
        _currentAnimationName = name;
        if (!animations)
        {
            throw std::runtime_error("Animations not set for AnimatedSprite2D.");
        }

        try
        {
            _currentAnimation = animations->at(name);
            if (continueAtCurrentFrame)
            {
                _currentFrameIndex = std::min(_currentFrameIndex,
                                              static_cast<unsigned int>(_currentAnimation.getFrames().size() - 1));
                _frameTimer = std::min(_frameTimer, _currentAnimation.getFrameDuration());
            }
            else
            {
                _currentFrameIndex = 0;
                _frameTimer = 0.0f;
            }
        }
        catch (const std::out_of_range& e)
        {
            // Handle the case where the animation name does not exist
            // For example, you could log an error message or throw an exception
            throw std::invalid_argument("Invalid animation name: " + name + ". Name not found in animations.");
        }
    }

    AnimatedSprite2D::AnimatedSprite2D(const std::unordered_map<std::string, framework::Animation>* animations) :
        animations(
            animations)
    {
    }

    void AnimatedSprite2D::_internal_onDraw()
    {
        _updateCurrentFrame(framework::Time::getDeltaTime());
        setTexture(*_currentAnimation.getFrames().at(_currentFrameIndex));
        Sprite2D::_internal_onDraw();
    }

    void AnimatedSprite2D::_updateCurrentFrame(const float deltaTime)
    {
        _frameTimer += deltaTime;
        while (_frameTimer >= _currentAnimation.getFrameDuration())
        {
            _frameTimer -= _currentAnimation.getFrameDuration();
            _currentFrameIndex++;
            if (_currentFrameIndex >= _currentAnimation.getFrames().size())
            {
                if (_currentAnimation.isLooping())
                {
                    _currentFrameIndex = 0;
                }
                else
                {
                    _currentFrameIndex = _currentAnimation.getFrames().size() - 1; // Stay on the last frame
                }
            }
        }
    }
} // framework
// e2XD
