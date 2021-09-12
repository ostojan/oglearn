set(LIBRARIES_LIST)

# Glad configuration
add_subdirectory(glad)
list(APPEND LIBRARIES_LIST glad)

# GLFW configuration
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw)
list(APPEND LIBRARIES_LIST glfw)

# OpenGL configuration
find_package(OpenGL REQUIRED)
list(APPEND LIBRARIES_LIST ${OPENGL_LIBRARIES})

set(EXTERNAL_LIBS ${LIBRARIES_LIST} PARENT_SCOPE)
