#ifndef APP_INC_BUFFEROBJECT_HPP
#define APP_INC_BUFFEROBJECT_HPP

#include <cassert>

#include <glad/glad.h>

namespace oglearn
{
    class BufferObject
    {
    protected:
        const GLenum type;
        GLuint id = -1;

    protected:
        BufferObject(GLenum type)
            : type(type)
        {
            glGenBuffers(1, &id);
        }

        virtual ~BufferObject()
        {
            assert(id != -1);
            glDeleteBuffers(1, &id);
        }

    public:
        inline const void Bind() const
        {
            assert(id != -1);
            glBindBuffer(type, id);
        }

        inline const void Unbind() const
        {
            glBindBuffer(type, 0);
        }
    };
}

#endif
