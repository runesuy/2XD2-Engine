//
// Created by rune-suy on 12/17/25.
//

#ifndef FLATLAND_FILELOADINGEXCEPTION_H
#define FLATLAND_FILELOADINGEXCEPTION_H
#include "Exception.h"

namespace e2XD::framework
{
    /**
     * Logic exception thrown when a file fails to load.
     */
    class FileLoadingFailedException : public Exception
    {
    public:
        FileLoadingFailedException(const std::string& filePath, const std::string& where) :
            Exception("Failed to load file: " + std::string(filePath), where)
        {
        }
    };
}

#endif //FLATLAND_FILELOADINGEXCEPTION_H
