#ifndef APP_INC_ELEMENTBUFFEROBJECT_HPP
#define APP_INC_ELEMENTBUFFEROBJECT_HPP

#include "BufferObject.hpp"

namespace oglearn
{
    class ElementBufferObject : public BufferObject
    {
    public:
        ElementBufferObject(const GLuint *indices, const unsigned int size);
    };
}

#endif
