#ifndef APP_INC_SHADER_HPP
#define APP_INC_SHADER_HPP

#include <string_view>

#include <glad/glad.h>

namespace oglearn
{
    class Shader
    {
    private:
        GLuint id = -1;

    public:
        Shader(GLenum type, const std::string_view path);
        ~Shader();

        inline const GLuint GetId() const
        {
            return id;
        }
    };
}

#endif
