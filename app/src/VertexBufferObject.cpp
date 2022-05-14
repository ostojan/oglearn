#include "VertexBufferObject.hpp"

namespace oglearn
{
    VertexBufferObject::VertexBufferObject(const GLfloat *vertices, const unsigned int size)
        : BufferObject(GL_ARRAY_BUFFER)
    {
        Bind();
        glBufferData(type, size, vertices, GL_STATIC_DRAW);
        Unbind();
    }
}
