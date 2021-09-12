set(APP_NAME "app")
set(APP_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

add_executable(${APP_NAME} ${APP_SOURCES})
target_link_libraries(${APP_NAME} PRIVATE ${EXTERNAL_LIBS})
