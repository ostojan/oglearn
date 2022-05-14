#ifndef APP_INC_VERTEXBUFFEROBJECT_HPP
#define APP_INC_VERTEXBUFFEROBJECT_HPP

#include "BufferObject.hpp"

namespace oglearn
{
    class VertexBufferObject : public BufferObject
    {
    public:
        VertexBufferObject(const GLfloat *vertices, const unsigned int size);
    };
}

#endif
