set(LIB_NAME "glad")
set(LIB_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LIB_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/glad.c)

add_library(${LIB_NAME} STATIC ${LIB_SOURCES})
target_include_directories(${LIB_NAME} PUBLIC ${LIB_INCLUDES})
