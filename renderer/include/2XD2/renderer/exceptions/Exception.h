//
// Created by runes on 15/12/2025.
//

#ifndef INC_2XD2_ENGINE_EXCEPTION_H
#define INC_2XD2_ENGINE_EXCEPTION_H

#include <iostream>
#include <ostream>

#include "exception"

class Exception : public std::exception {
    const char* msg;
    const char* where;
public:
    explicit Exception(const char* message, const char* where) : msg(message), where(where) {
        std::cerr << "Exception occurred in " << where << std::endl;
    }

    [[nodiscard]] const char* what() const noexcept override {
        return msg;
    }

    [[nodiscard]] const char* whereOccurred() const noexcept {
        return where;
    }
};

#endif //INC_2XD2_ENGINE_EXCEPTION_H