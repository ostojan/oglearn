set(LIB_NAME "stb_image")
set(LIB_INCLUDES
    ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(LIB_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/stb_image.cpp)

add_library(${LIB_NAME} STATIC ${LIB_SOURCES})
target_include_directories(${LIB_NAME} PUBLIC ${LIB_INCLUDES})
