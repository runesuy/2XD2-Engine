//
// Created by runes on 15/12/2025.
//

#ifndef INC_2XD2_ENGINE_FRAMEWORKNOTINITIALIZEDEXCEPTION_H
#define INC_2XD2_ENGINE_FRAMEWORKNOTINITIALIZEDEXCEPTION_H

#include "Exception.h"

namespace e2DX::framework
{
    class NotInitializedException : public Exception {
    public:
        NotInitializedException(const char* whatIsNotInitialized, const char* where)
            : Exception((std::string(whatIsNotInitialized) + " has not been initialized.").c_str(), where) {}
    };
}

#endif //INC_2XD2_ENGINE_FRAMEWORKNOTINITIALIZEDEXCEPTION_H