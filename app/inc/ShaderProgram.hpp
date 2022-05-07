#ifndef APP_INC_SHADERPROGRAM_HPP
#define APP_INC_SHADERPROGRAM_HPP

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
    };
}

#endif
