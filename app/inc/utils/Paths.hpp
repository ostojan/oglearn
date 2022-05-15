#ifndef APP_INC_UTILS_PATHS_HPP
#define APP_INC_UTILS_PATHS_HPP

namespace oglearn::utils::paths
{
    namespace shaders
    {
        // Basic
        constexpr const char *basicVertexShader = "shaders/basic/vertex.glsl";
        constexpr const char *basicFragmentShader = "shaders/basic/fragment.glsl";
        // Texture
        constexpr const char *texturesVertexShader = "shaders/textures/vertex.glsl";
        constexpr const char *texturesFragmentShader = "shaders/textures/fragment.glsl";
    }

    namespace textures
    {
        constexpr const char *containerTexture = "textures/container.jpg";
    }
}

#endif
