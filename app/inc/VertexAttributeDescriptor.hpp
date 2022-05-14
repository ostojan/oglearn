#ifndef APP_INC_VERTEXATTRIBUTEDESCRIPTOR_HPP
#define APP_INC_VERTEXATTRIBUTEDESCRIPTOR_HPP

#include <glad/glad.h>

namespace oglearn
{
    struct VertexAttributeDescriptor
    {
        GLuint index = -1;
        GLint size = -1;
        GLenum type = GL_FLOAT;
        GLboolean normalized = GL_FALSE;
        GLsizei stride = -1;
        GLuint offset = 0;
    };
}

#endif
