#include "File.hpp"

#include <fstream>
#include <stdexcept>

namespace utils
{
    namespace file
    {
        std::string loadFileContent(const std::string_view filePath)
        {
            std::ifstream file(filePath, std::ios::in | std::ios::ate);
            if (!file)
            {
                throw std::runtime_error("Couldn't open file");
            }
            std::string result;
            result.reserve(file.tellg());
            file.seekg(0, std::ios::beg);
            result.assign((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
            return result;
        }
    }

}
