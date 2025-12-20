# Getting Started with 2XD2-Engine

## Prerequisites
Before you begin, ensure you have the following installed on your system:
- A C++ compiler that supports C++11 or later.
- CMake (version 3.10 or later).
- SFML library (version 2.5 or later). You can download it from the [official SFML website](https://www.sfml-dev.org/download.php).
- Git (optional, for cloning the repository).
- A code editor or IDE of your choice (e.g., Visual Studio, CLion, VSCode).
- Basic knowledge of C++ and CMake.

## Installation
### Using Cmake
1. Download or clone the 2XD2-Engine repository:
   ```bash
   git clone https://github.com/runesuy/2XD2-Engine.git
    ```
   
2. In your CMakeLists.txt, add the following lines to include 2XD2-Engine as a subdirectory:
   ```cmake
   add_subdirectory(path/to/2XD2-Engine)
   target_link_libraries(your_project_name PRIVATE 2XD2-Engine)
   ```
3. The library will automatically link against the SFML libraries. Ensure that SFML is correctly installed and accessible in your development environment.

## Creating a Simple Application
The easiest way to get started with 2XD2-Engine is to create a simple application using the 2XD2-Engine framework. Below is a basic example of how to set up a windowed application.

```cpp
#include "2XD2/framework/Game.h"

using namespace e2XD::framework;

int main() {
    Game game;

    game.setWindowTitle("My First 2XD2-Engine Game");

    game.run();

    return 0;
}
```

When calling run(), the framework will create a window and start the main loop.

## Learning More
To learn more about 2XD2-Engine and its features, refer to the following resources:
- [API Documentation](https://github.com/runesuy/2XD2-Engine/pages): Detailed documentation of the engine's classes and functions.

More guides coming soon!
