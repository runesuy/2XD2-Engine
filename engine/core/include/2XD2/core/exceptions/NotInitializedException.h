//
// Created by runes on 15/12/2025.
//

#ifndef INC_2XD2_ENGINE_FRAMEWORKNOTINITIALIZEDEXCEPTION_H
#define INC_2XD2_ENGINE_FRAMEWORKNOTINITIALIZEDEXCEPTION_H

#include "Exception.h"

namespace e2XD::core
{
    /**
     * Exception thrown when a component is used before being initialized.
     */
    class NotInitializedException : public Exception
    {
    public:
        NotInitializedException(const std::string& whatIsNotInitialized, const std::string& where)
            : Exception(whatIsNotInitialized + " has not been initialized.", where)
        {
        }
    };
}

#endif //INC_2XD2_ENGINE_FRAMEWORKNOTINITIALIZEDEXCEPTION_H
