//
// Created by rune-suy on 12/17/25.
//

#include <gtest/gtest.h>
#include "../../framework/include/2XD2/framework/resource_manager/SFMLTextureManager.h"


namespace e2XD::framework
{
    class FRAMEWORK_SFMLTextureParser_TEST : public ::testing::Test
    {
    public:
        static const std::unordered_map<std::string, sf::Texture>& getLoadedTextures()
        {
            return SFMLTextureManager::getInstance()->loadedTextures;
        }
    };

    TEST_F(FRAMEWORK_SFMLTextureParser_TEST, getInstanceTest)
    {
        SFMLTextureManager* instance1 = SFMLTextureManager::getInstance();
        SFMLTextureManager* instance2 = SFMLTextureManager::getInstance();
        ASSERT_EQ(instance1, instance2);
        ASSERT_TRUE(instance1);
        ASSERT_TRUE(instance2);
    }

    TEST_F(FRAMEWORK_SFMLTextureParser_TEST, loadJsonTextureConfigTest)
    {
        SFMLTextureManager* parser = SFMLTextureManager::getInstance();
        ASSERT_NO_THROW(parser->loadJsonTextureConfig("resources/input/test_textures.json"));

        const auto& textures = getLoadedTextures();
        ASSERT_EQ(textures.size(), 4); // Assuming the JSON file defines 2 textures

        // Check if specific textures are loaded
        ASSERT_TRUE(textures.contains("texture1"));
        ASSERT_TRUE(textures.contains("texture2"));
        ASSERT_TRUE(textures.contains("texture3"));
        ASSERT_TRUE(textures.contains("texture4"));
    }

    TEST_F(FRAMEWORK_SFMLTextureParser_TEST, getTextureTest)
    {
        SFMLTextureManager* parser = SFMLTextureManager::getInstance();
        parser->loadJsonTextureConfig("resources/input/test_textures.json");

        ASSERT_NO_THROW({
            const sf::Texture& texture1 = parser->getTexture("texture1");
            const sf::Texture& texture2 = parser->getTexture("texture2");
        });

        ASSERT_THROW({
            const sf::Texture& texture3 = parser->getTexture("non_existent_texture");
        }, std::invalid_argument);
    }
} // framework
// e2XD
