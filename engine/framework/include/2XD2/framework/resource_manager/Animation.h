//
// Created by rune-suy on 12/17/25.
//

#ifndef FLATLAND_ANIMATION_H
#define FLATLAND_ANIMATION_H
#include <vector>
#include <SFML/Graphics/Texture.hpp>


namespace e2XD::framework
{
    /**
     * Animation class representing a sequence of frames (textures) with timing and looping information.
     */
    class Animation
    {
        float _frameDuration = 0.1f; // Duration of each frame in seconds
        bool _isLooping = false;
        std::vector<const sf::Texture*> frames;

    public:
        Animation() = default;
        Animation(const std::initializer_list<const sf::Texture*>& frameList, float frameDuration,
                  bool isLooping = false);
        Animation(const std::vector<const sf::Texture*>& frameList, float frameDuration, bool isLooping = false);

        /**
         * Add a frame to the animation.
         * @param texture Pointer to the texture to add as a frame.
         */
        void addFrame(sf::Texture* texture);

        /**
         * Set the duration of each frame in seconds.
         * @param duration Duration in seconds.
         */
        void setFrameDuration(float duration);

        /**
         * Set whether the animation should loop.
         * @param looping True if the animation should loop, false otherwise.
         */
        void setLooping(bool looping);

        /**
         *
         * @return a const reference to the vector of frame textures.
         */
        [[nodiscard]] const std::vector<const sf::Texture*>& getFrames() const;

        /**
         *
         * @return the frame duration in seconds.
         */
        [[nodiscard]] float getFrameDuration() const;

        /**
         *
         * @return true if the animation is set to loop, false otherwise.
         */
        [[nodiscard]] bool isLooping() const;
    };
} // framework
// e2XD

#endif //FLATLAND_ANIMATION_H
