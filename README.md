# 2XD2-Engine
***

## Overview 
2XD2-Engine is a 2D game engine built with C++ and SFML.
The main objectsives of this project are to provide an easy-to-use framework for developing 2D games and to offer a modular architecture that allows developers to extend and customize the engine according to their needs.

**This project is still in its early stages of development, all contributions are welcome!**

## Features

- **Node-based architecture**: The engine is built around a node system, allowing for easy management of game objects and their relationships.
- **Scene management**: Easily create and switch between different scenes in your game.
- **Event handling**: Built-in event system for handling user input and other events using SFML.
- **Rendering**: Simple rendering system using SFML for drawing sprites, shapes, and text.
- **Resource management**: Load and manage game assets such as textures, fonts, and sounds, animations. (WIP)
- **Collision handling**: Powerfull and efficient collision system. (COMING SOON)
- **Physics simulation**: Modular and easily extendable physics base. (COMING SOON)

I plan to add more features in the future, such as physics integration, audio support, and further optimizations and modularity improvements.

## Getting Started

### Manual Installation
1. Download and install SFML from [the official website](https://www.sfml-dev.org/download.php).
2. Manually install 2XD2-Engine:
   1. By cloning the repository:
      ```bash
      git clone https://github.com/runesuy/2XD2-Engine.git
       ```
   2. Or downloading one of the release packages from the [releases page](https://github.com/runesuy/2XD2-Engine/releases).
3. Include the 2XD2-Engine headers and link against the SFML libraries in your C++ project.

### Using CMake
You can also use CMake to manage your project and include 2XD2-Engine as a subdirectory.
1. Clone the repository:
   ```bash
   git clone  https://github.com/runesuy/2XD2-Engine.git
    ```
2. In your CMakeLists.txt, add the following lines:
   ```cmake
   add_subdirectory(path/to/2XD2-Engine)
   target_link_libraries(your_project_name PRIVATE 2XD2-Engine)
   ```

For more information on setting up SFML, refer to the [SFML tutorials](https://www.sfml-dev.org/tutorials/3.0/).
For more detailed instructions on using 2XD2-Engine, refer to the [getting started guide](GettingStarted.md).

## Contributing
Contributions are welcome! If you would like to contribute to 2XD2-Engine, please follow these steps:
1. Fork the repository.
2. Create a new branch for your feature or bug fix.
3. Make your changes and commit them with clear messages.
4. Push your changes to your forked repository.
5. Create a pull request to the main repository.

Please ensure that your code adheres to the existing coding style and includes appropriate tests.

For more details, refer to the [contributing guidelines](CONTRIBUTING.md).

## Join the [Discord](https://discord.gg/sVJzxWWbdW)

Links:
- [doxygen delveloper docs](https://runesuy.github.io/2XD2-Engine/)
