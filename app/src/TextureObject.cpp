#include "TextureObject.hpp"

#include <unordered_map>

#include "stb_image.h"

namespace oglearn
{
    TextureObject::TextureObject(const std::string_view path, unsigned int textureId)
        : textureId(textureId)
    {
        auto width = 0;
        auto height = 0;
        auto numChannels = 0;
        stbi_set_flip_vertically_on_load(true);
        auto *imageData = stbi_load(path.data(), &width, &height, &numChannels, 0);
        if (!imageData)
        {
            throw std::runtime_error("Failed to load texture file");
        }
        GLenum imageFormat;
        switch (numChannels)
        {
        case 3:
            imageFormat = GL_RGB;
            break;
        case 4:
            imageFormat = GL_RGBA;
            break;
        default:
            throw std::runtime_error("Unsuported image format");
        }

        glGenTextures(1, &id);
        Bind();
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, imageFormat, GL_UNSIGNED_BYTE, imageData);
        glGenerateMipmap(GL_TEXTURE_2D);
        Unbind();

        stbi_image_free(imageData);
    }

    TextureObject::~TextureObject()
    {
        assert(id != -1);
        glDeleteTextures(1, &id);
    }
}
