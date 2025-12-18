//
// Created by rune-suy on 12/17/25.
//

#ifndef FLATLAND_FILELOADINGEXCEPTION_H
#define FLATLAND_FILELOADINGEXCEPTION_H
#include "2XD2/framework/exceptions/Exception.h"

namespace e2XD::framework
{
    class FileLoadingFailedException : public Exception
    {
    public:
        FileLoadingFailedException(const std::string& filePath, const std::string& where) :
            Exception(("Failed to load file: " + std::string(filePath)).c_str(), where)
        {
        }
    };
}

#endif //FLATLAND_FILELOADINGEXCEPTION_H