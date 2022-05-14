#include "VertexArrayObject.hpp"

namespace oglearn
{
    VertexArrayObject::VertexArrayObject(const VertexBufferObject &vbo,
                                         const VertexAttributeDescriptor *attributeDescriptors,
                                         const unsigned int numDescriptors,
                                         const ElementBufferObject &ebo)
    {
        glGenVertexArrays(1, &id);
        Bind();
        vbo.Bind();
        for (auto descriptorIdx = 0u; descriptorIdx < numDescriptors; descriptorIdx++)
        {
            const auto &descriptor = attributeDescriptors[descriptorIdx];
            glVertexAttribPointer(descriptor.index,
                                  descriptor.size,
                                  descriptor.type,
                                  descriptor.normalized,
                                  descriptor.stride,
                                  reinterpret_cast<const void *>(descriptor.offset));
            glEnableVertexAttribArray(descriptor.index);
        }
        ebo.Bind();
        Unbind();
        vbo.Unbind();
        ebo.Unbind();
    }

    VertexArrayObject::~VertexArrayObject()
    {
        assert(id != -1);
        glDeleteVertexArrays(1, &id);
    }
}
