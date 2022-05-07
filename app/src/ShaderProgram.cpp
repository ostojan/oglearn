#include "ShaderProgram.hpp"

#include <array>

namespace oglearn
{
    ShaderProgram::ShaderProgram()
    {
        id = glCreateProgram();
    }

    ShaderProgram::~ShaderProgram()
    {
        if (id != -1)
        {
            glDeleteProgram(id);
        }
    }

    void ShaderProgram::AttachShader(const Shader &shader) const
    {
        glAttachShader(id, shader.GetId());
    }

    void ShaderProgram::Link() const
    {
        glLinkProgram(id);
        GLint success = 0;
        glGetProgramiv(id, GL_LINK_STATUS, &success);
        if (!success)
        {
            std::array<GLchar, 512> infoLog;
            glGetProgramInfoLog(id, infoLog.size(), nullptr, infoLog.data());
            throw std::runtime_error(infoLog.data());
        }
    }

    void ShaderProgram::Use() const
    {
        glUseProgram(id);
    }
}
