
add_library(webgame_render STATIC
    render.c
)
target_include_directories(webgame_render PUBLIC ..)

target_link_libraries(webgame_render PUBLIC webgame::base glfw)
if(NOT EMSCRIPTEN)
    find_package(OpenGL REQUIRED)

    target_link_libraries(webgame_render PUBLIC OpenGL::OpenGL)
endif()

add_library(webgame::render ALIAS webgame_render)

