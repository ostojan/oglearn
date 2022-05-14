#ifndef APP_INC_SHADERPROGRAM_HPP
#define APP_INC_SHADERPROGRAM_HPP

#include <string_view>

#include <glad/glad.h>

#include "Shader.hpp"

namespace oglearn
{
    class ShaderProgram
    {
    private:
        GLuint id = -1;

    public:
        ShaderProgram();
        ~ShaderProgram();

        void AttachShader(const Shader &shader) const;
        void Link() const;
        void Use() const;

        template <typename T>
        void SetUniform1(const std::string_view name, const T value1) const;
        template <typename T>
        void SetUniform2(const std::string_view name, const T value1, const T value2) const;
        template <typename T>
        void SetUniform3(const std::string_view name, const T value1, const T value2, const T value3) const;
        template <typename T>
        void SetUniform4(const std::string_view name, const T value1, const T value2, const T value3, const T value4) const;

    private:
        const GLint GetUniformLocation(const std::string_view name) const;
    };
}

#endif
