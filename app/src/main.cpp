#include <array>
#include <iostream>
#include <stdexcept>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ElementBufferObject.hpp"
#include "Shader.hpp"
#include "ShaderProgram.hpp"
#include "TextureObject.hpp"
#include "VertexArrayObject.hpp"
#include "VertexAttributeDescriptor.hpp"
#include "VertexBufferObject.hpp"
#include "utils/Paths.hpp"

constexpr int windowWidth = 800;
constexpr int windowHeight = 600;

void initializeGlfw()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow *createWindow()
{
    auto window = glfwCreateWindow(windowWidth, windowHeight, "OpenGL App Template", nullptr, nullptr);
    if (window == nullptr)
    {
        throw std::runtime_error("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(window);
    return window;
}

void initializeGlad()
{
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw std::runtime_error("Failed to initialize GLAD");
    }
}

void framebufferSizeCallback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }
}

int main(int argCount, const char *const *const argValues)
{
    try
    {
        initializeGlfw();
        auto window = createWindow();
        initializeGlad();

        int width = 0;
        int height = 0;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

        oglearn::ShaderProgram program;
        {
            oglearn::Shader vertexShader{GL_VERTEX_SHADER, oglearn::utils::paths::shaders::texturesVertexShader};
            oglearn::Shader fragmentShader{GL_FRAGMENT_SHADER, oglearn::utils::paths::shaders::texturesFragmentShader};

            program.AttachShader(vertexShader);
            program.AttachShader(fragmentShader);
            program.Link();
        }

        std::array<GLfloat, 32> vertexAttributes{
            0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f,   // top right
            0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // bottom left
            -0.5f, 0.5f, 0.0f, 0.5f, 0.5f, 0.5f, 0.0f, 1.0f,  // top left
        };
        std::array<oglearn::VertexAttributeDescriptor, 3> vertexAttrbuteDescriptors{{
            {0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 0},                 // vertex position
            {1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 3 * sizeof(float)}, // vertex color
            {2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), 6 * sizeof(float)}, // texture coordinates
        }};
        oglearn::VertexBufferObject vbo{vertexAttributes.data(), sizeof(vertexAttributes)};

        std::array<GLuint, 6> indices{
            0, 1, 2, // first triangle
            0, 2, 3, // second triangle
        };
        oglearn::ElementBufferObject ebo{indices.data(), sizeof(indices)};

        oglearn::VertexArrayObject vao{vbo, vertexAttrbuteDescriptors.data(), vertexAttrbuteDescriptors.size(), ebo};

        oglearn::TextureObject texture{oglearn::utils::paths::textures::containerTexture, 0u};

        while (!glfwWindowShouldClose(window))
        {
            processInput(window);

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            texture.Bind();
            program.Use();
            program.SetUniform1("texture1", static_cast<int>(texture.GetTextureId()));
            vao.Bind();
            glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);

            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glfwTerminate();
    }
    catch (std::runtime_error &error)
    {
        std::cerr << error.what() << std::endl;
        glfwTerminate();
        return -1;
    }

    return 0;
}
