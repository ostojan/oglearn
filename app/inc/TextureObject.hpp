#ifndef APP_INC_TEXTUREOBJECT_HPP
#define APP_INC_TEXTUREOBJECT_HPP

#include <cassert>
#include <string_view>

#include <glad/glad.h>

namespace oglearn
{
    class TextureObject
    {
    private:
        GLuint id = -1;
        unsigned int textureId = 0;

    public:
        TextureObject(const std::string_view path, unsigned int textureId = 0u);
        ~TextureObject();

        inline const void Bind() const
        {
            assert(id != -1);
            glActiveTexture(GL_TEXTURE0 + textureId);
            glBindTexture(GL_TEXTURE_2D, id);
        }

        inline const void Unbind() const
        {
            glBindTexture(GL_TEXTURE_2D, 0);
        }

        inline unsigned int GetTextureId() const
        {
            return textureId;
        }

        inline void SetTextureId(unsigned int newTextureId)
        {
            textureId = newTextureId;
        }
    };
}

#endif
