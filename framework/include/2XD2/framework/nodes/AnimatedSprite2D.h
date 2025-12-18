//
// Created by rune-suy on 12/17/25.
//

#ifndef FLATLAND_ANIMATEDSPRITE2D_H
#define FLATLAND_ANIMATEDSPRITE2D_H
#include <unordered_map>

#include "Sprite2D.h"
#include "2XD2/framework/Animation.h"
#include "2XD2/framework/AnimationMap.h"


namespace e2XD::framework
{
    class AnimatedSprite2D : public Sprite2D
    {
        Animation _currentAnimation;
        std::string _currentAnimationName;
        const AnimationMap* animations=nullptr;
        unsigned int _currentFrameIndex=0;
        float _frameTimer=0.0f;

        void _updateCurrentFrame(float deltaTime);

    public:
        AnimatedSprite2D() = default;
        explicit AnimatedSprite2D(const AnimationMap* animations);
        ~AnimatedSprite2D() override = default;

        void playAnimation(const std::string& name, bool continueAtCurrentFrame=false);

        /**
         * Unordered map of all animations available for this sprite.
         * Map needs to be kept alive as long as the AnimatedSprite2D uses it.
         * @param newAnimations
         */
        void setAnimations(const AnimationMap& newAnimations);


    protected:
        void _internal_onDraw() override;
    };
} // framework
// e2XD

#endif //FLATLAND_ANIMATEDSPRITE2D_H
