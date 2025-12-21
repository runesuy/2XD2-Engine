//
// Created by rune-suy on 12/21/25.
//

#ifndef INC_2XD2_ENGINE_ITEXTUREMANAGER_H
#define INC_2XD2_ENGINE_ITEXTUREMANAGER_H
#include <string>
#include <SFML/Graphics/Texture.hpp>


namespace e2XD::framework
{
    /**
     * Texture manager interface
     * Used to manage textures in the framework.
     * Can be implemented and passed to Resources::Textures to provide custom texture management.
     */
    class ITextureManager
    {
    public:
        virtual ~ITextureManager() = default;

        /**
         * @pre The texture with the given name must be loaded in the manager.
         * @param name
         * @return the texture associated with the given name.
         */
        [[nodiscard]] virtual const sf::Texture& getTexture(const std::string& name) const =0;

        /**
         *
         * @param jsonFilePath load textures in the manager using a json config file.
         * Json format:
         * @code
         * {
         *"files": [
         *      {
         *        "filename": "filename1",
         *        "textures": [
         *          {"texture-name": "texture1", "texture-select": {"x": 0, "y": 0, "height": 10, "width": 10}},
         *          {"texture-name": "texture2", "texture-select": {"x": 0, "y": 0, "height": 10, "width": 10}}
         *        ]
         *      },
         *      {
         *        "filename": "filename2",
         *        "textures": [
         *          {"texture-name": "texture3", "texture-select": {"x": 0, "y": 0, "height": 10, "width": 10}},
         *          {"texture-name": "texture4", "texture-select": {"x": 0, "y": 0, "height": 10, "width": 10}}
         *        ]
         *      }
         *  ]
         *}
         *@endcode
         */
        virtual void loadJsonTextureConfig(const std::string& jsonFilePath) =0;

        /**
         *
         * @param jsonFilePath
         * @return true if the json texture config file has already been loaded in the manager.
         */
        [[nodiscard]] virtual bool isJsonTextureLoaded(const std::string& jsonFilePath) const =0;

        /**
         * Load textures in the manager using a json config file if it has not been loaded yet.
         * @param jsonFilePath
         * @return true if the json texture config file was not loaded and has been loaded by this call.
         */
        virtual bool loadJsonTextureConfigIfNotLoaded(const std::string& jsonFilePath) =0;
    };
} // framework
// e2XD

#endif //INC_2XD2_ENGINE_ITEXTUREMANAGER_H
