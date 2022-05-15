set(APP_NAME "app")
set(APP_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(APP_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ElementBufferObject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/Shader.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/ShaderProgram.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/TextureObject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/VertexArrayObject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/VertexBufferObject.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

set(APP_SHADERS_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/shaders)
set(APP_SHADERS
    basic/fragment.glsl
    basic/vertex.glsl)

foreach(SHADER IN LISTS APP_SHADERS)
    set(SHADER_INPUT_PATH ${APP_SHADERS_ROOT}/${SHADER})
    set(SHADER_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/shaders/${SHADER})
    add_custom_command(OUTPUT ${SHADER_OUTPUT_PATH}
                       COMMAND ${CMAKE_COMMAND} -E copy ${SHADER_INPUT_PATH} ${SHADER_OUTPUT_PATH}
                       DEPENDS ${SHADER_INPUT_PATH})
    list(APPEND APP_SOURCES ${SHADER_OUTPUT_PATH})
endforeach()

set(APP_TEXTURES_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/textures)
set(APP_TEXTURES
    container.jpg)

set(APP_RESOURCES)
foreach(TEXTURE IN LISTS APP_TEXTURES)
    set(TEXTURE_INPUT_PATH ${APP_TEXTURES_ROOT}/${TEXTURE})
    set(TEXTURE_OUTPUT_PATH ${CMAKE_CURRENT_BINARY_DIR}/textures/${TEXTURE})
    add_custom_command(OUTPUT ${TEXTURE_OUTPUT_PATH}
                       COMMAND ${CMAKE_COMMAND} -E copy ${TEXTURE_INPUT_PATH} ${TEXTURE_OUTPUT_PATH}
                       DEPENDS ${TEXTURE_INPUT_PATH})
    list(APPEND APP_RESOURCES ${TEXTURE_OUTPUT_PATH})
endforeach()

add_executable(${APP_NAME} ${APP_SOURCES} ${APP_RESOURCES})
target_link_libraries(${APP_NAME} PRIVATE ${EXTERNAL_LIBS} ${UTILS_LIBS})
target_include_directories(${APP_NAME} PRIVATE ${APP_INCLUDES})

if (APPLE)
    target_compile_definitions(${APP_NAME} PRIVATE GL_SILENCE_DEPRECATION)
endif()
