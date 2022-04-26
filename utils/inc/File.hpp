#ifndef UTILS_INC_FILE_HPP
#define UTILS_INC_FILE_HPP

#include <string>

namespace utils
{
    namespace file
    {
        std::string loadFileContent(const std::string_view filePath);
    }

}

#endif
