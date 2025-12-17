//
// Created by runes on 15/12/2025.
//

#ifndef INC_2XD2_ENGINE_RENDERERNOTINITIALIZEDEXCEPTION_H
#define INC_2XD2_ENGINE_RENDERERNOTINITIALIZEDEXCEPTION_H

#include "Exception.h"

class NotInitializedException : public Exception {
public:
    explicit NotInitializedException(std::string where)
        : Exception("Renderer has not been initialized.", std::move(where)) {}
};

#endif //INC_2XD2_ENGINE_RENDERERNOTINITIALIZEDEXCEPTION_H