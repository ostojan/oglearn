#ifndef APP_INC_VERTEXARRAYOBJECT_HPP
#define APP_INC_VERTEXARRAYOBJECT_HPP

#include <cassert>

#include <glad/glad.h>

#include "VertexAttributeDescriptor.hpp"
#include "VertexBufferObject.hpp"
#include "ElementBufferObject.hpp"

namespace oglearn
{
    class VertexArrayObject
    {
    private:
        GLuint id = -1;

    public:
        VertexArrayObject(const VertexBufferObject &vbo,
                          const VertexAttributeDescriptor *attributeDescriptors,
                          const unsigned int numDescriptors,
                          const ElementBufferObject &ebo);
        ~VertexArrayObject();

        inline const void Bind() const
        {
            assert(id != -1);
            glBindVertexArray(id);
        }

        inline const void Unbind() const
        {
            glBindVertexArray(0);
        }
    };
}

#endif
