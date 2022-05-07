#include "Shader.hpp"

#include <array>

#include "File.hpp"

namespace oglearn
{
    Shader::Shader(GLenum type, const std::string_view path)
    {
        auto shaderSource = utils::file::loadFileContent(path);
        const auto shaderSourcePtr = shaderSource.c_str();
        id = glCreateShader(type);
        glShaderSource(id, 1, &shaderSourcePtr, nullptr);
        glCompileShader(id);
        GLint success = 0;
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            std::array<GLchar, 512> infoLog;
            glGetShaderInfoLog(id, infoLog.size(), nullptr, infoLog.data());
            throw std::runtime_error(infoLog.data());
        }
    }

    Shader::~Shader()
    {
        if (id != -1)
        {
            glDeleteShader(id);
        }
    }
}
