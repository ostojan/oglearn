#include <array>
#include <iostream>
#include <stdexcept>

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Shader.hpp"
#include "ShaderProgram.hpp"
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
            oglearn::Shader vertexShader{GL_VERTEX_SHADER, oglearn::utils::paths::shaders::basicVertexShader};
            oglearn::Shader fragmentShader{GL_FRAGMENT_SHADER, oglearn::utils::paths::shaders::basicFragmentShader};

            program.AttachShader(vertexShader);
            program.AttachShader(fragmentShader);
            program.Link();
        }

        GLuint vao = -1;
        {
            glGenVertexArrays(1, &vao);
            glBindVertexArray(vao);

            std::array vertexAttributes = {
                -0.5f, -0.5f, 0.0f, // 1st
                0.5f, -0.5f, 0.0f,  // 2nd
                0.0f, 0.5f, 0.0f,   // 3rd
            };

            GLuint vbo = -1;
            glGenBuffers(1, &vbo);
            glBindBuffer(GL_ARRAY_BUFFER, vbo);
            glBufferData(GL_ARRAY_BUFFER, sizeof(vertexAttributes), vertexAttributes.data(), GL_STATIC_DRAW);

            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
            glEnableVertexAttribArray(0);

            glBindVertexArray(0);
        }

        while (!glfwWindowShouldClose(window))
        {
            processInput(window);

            glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT);

            program.Use();
            glBindVertexArray(vao);
            glDrawArrays(GL_TRIANGLES, 0, 3);

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
