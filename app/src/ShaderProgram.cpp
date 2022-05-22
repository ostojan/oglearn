#include "ShaderProgram.hpp"

#include <array>

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

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

    template <>
    void ShaderProgram::SetUniform1(const std::string_view name, const float value1) const
    {
        glUniform1f(GetUniformLocation(name), value1);
    }

    template <>
    void ShaderProgram::SetUniform2(const std::string_view name, const float value1, const float value2) const
    {
        glUniform2f(GetUniformLocation(name), value1, value2);
    }

    template <>
    void ShaderProgram::SetUniform3(const std::string_view name, const float value1, const float value2, const float value3) const
    {
        glUniform3f(GetUniformLocation(name), value1, value2, value3);
    }

    template <>
    void ShaderProgram::SetUniform4(const std::string_view name, const float value1, const float value2, const float value3, const float value4) const
    {
        glUniform4f(GetUniformLocation(name), value1, value2, value3, value4);
    }

    template <>
    void ShaderProgram::SetUniform1(const std::string_view name, const int value1) const
    {
        glUniform1i(GetUniformLocation(name), value1);
    }

    template <>
    void ShaderProgram::SetUniform2(const std::string_view name, const int value1, const int value2) const
    {
        glUniform2i(GetUniformLocation(name), value1, value2);
    }

    template <>
    void ShaderProgram::SetUniform3(const std::string_view name, const int value1, const int value2, const int value3) const
    {
        glUniform3i(GetUniformLocation(name), value1, value2, value3);
    }

    template <>
    void ShaderProgram::SetUniform4(const std::string_view name, const int value1, const int value2, const int value3, const int value4) const
    {
        glUniform4i(GetUniformLocation(name), value1, value2, value3, value4);
    }

    template <>
    void ShaderProgram::SetUniform1(const std::string_view name, const unsigned int value1) const
    {
        glUniform1ui(GetUniformLocation(name), value1);
    }

    template <>
    void ShaderProgram::SetUniform2(const std::string_view name, const unsigned int value1, const unsigned int value2) const
    {
        glUniform2ui(GetUniformLocation(name), value1, value2);
    }

    template <>
    void ShaderProgram::SetUniform3(const std::string_view name, const unsigned int value1, const unsigned int value2, const unsigned int value3) const
    {
        glUniform3ui(GetUniformLocation(name), value1, value2, value3);
    }

    template <>
    void ShaderProgram::SetUniform4(const std::string_view name, const unsigned int value1, const unsigned int value2, const unsigned int value3, const unsigned int value4) const
    {
        glUniform4ui(GetUniformLocation(name), value1, value2, value3, value4);
    }

    template <>
    void ShaderProgram::SetUniformV(const std::string_view name, const glm::mat4x4 &value) const
    {
        glUniformMatrix4fv(GetUniformLocation(name), 1, GL_FALSE, glm::value_ptr(value));
    }

    const GLint ShaderProgram::GetUniformLocation(const std::string_view name) const
    {
        auto location = glGetUniformLocation(id, name.data());
        assert(location != -1);
        return location;
    }
}
