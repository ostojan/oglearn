set(LIB_NAME "utils")
set(LIB_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/inc)
set(LIB_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/File.cpp)

add_library(${LIB_NAME} STATIC ${LIB_SOURCES})
target_include_directories(${LIB_NAME} PUBLIC ${LIB_INCLUDES})

set(UTILS_LIBS ${LIB_NAME} PARENT_SCOPE)
