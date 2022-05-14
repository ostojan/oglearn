#include "ElementBufferObject.hpp"

namespace oglearn
{
    ElementBufferObject::ElementBufferObject(const GLuint *indices, const unsigned int size)
        : BufferObject(GL_ELEMENT_ARRAY_BUFFER)
    {
        Bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
        Unbind();
    }
}
