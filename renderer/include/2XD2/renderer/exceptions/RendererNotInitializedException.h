//
// Created by runes on 15/12/2025.
//

#ifndef INC_2XD2_ENGINE_RENDERERNOTINITIALIZEDEXCEPTION_H
#define INC_2XD2_ENGINE_RENDERERNOTINITIALIZEDEXCEPTION_H

#include "Exception.h"

class RendererNotInitializedException : public Exception {
public:
    RendererNotInitializedException(const char* where)
        : Exception("Renderer has not been initialized.", where) {}
};

#endif //INC_2XD2_ENGINE_RENDERERNOTINITIALIZEDEXCEPTION_H