# A Quick Word On Renderables

For consistency reasons. std-addon renderables have as their only function to provide primitive renderable objects by µ
extending SFML functionality, acting like an interface between SFML and the 2XD2 rendering system.

This means that thing slike origin-handling, rotation and positioning if present, must use local and precise positioning.
Advanced layout and positioning should be handled by higher level objects.