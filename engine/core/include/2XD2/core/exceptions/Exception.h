//
// Created by runes on 15/12/2025.
//

#ifndef INC_2XD2_ENGINE_EXCEPTION_H
#define INC_2XD2_ENGINE_EXCEPTION_H

#include <iostream>
#include <ostream>
#include <utility>

#include "exception"


namespace e2XD::framework
{
    /**
     * Default exception class for the engine.
     */
    class Exception : public std::exception
    {
        const std::string msg;
        const std::string where;

    public:
        explicit Exception(std::string message, std::string where) : msg(std::move(message)), where(std::move(where))
        {
            std::cerr << "Exception occurred in " << where << std::endl;
        }

        [[nodiscard]] const char* what() const noexcept override
        {
            return msg.c_str();
        }

        [[nodiscard]] const char* whereOccurred() const noexcept
        {
            return where.c_str();
        }
    };
}

#endif //INC_2XD2_ENGINE_EXCEPTION_H