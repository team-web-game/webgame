
add_library(webgame_render STATIC
    app.cpp
    app.h
    file_mesh.cpp
    file_mesh.h
    geometry.cpp
    geometry.h
    mesh.cpp
    mesh.h
    render.h
    render_error.h
)
target_include_directories(webgame_render PUBLIC ..)

target_link_libraries(webgame_render PUBLIC webgame::base glad::glad)
if(NOT EMSCRIPTEN)
    find_package(OpenGL REQUIRED)

    target_link_libraries(webgame_render PUBLIC OpenGL::OpenGL glfw)
else()
    target_link_options(webgame_render PUBLIC -sUSE_GLFW=3)
endif()

add_library(webgame::render ALIAS webgame_render)

