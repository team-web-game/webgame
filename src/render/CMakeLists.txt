
add_library(webgame_render STATIC
    render.c
)
target_include_directories(webgame_render PUBLIC ..)

target_link_libraries(webgame_render PUBLIC webgame::base)
if(!EMSCRIPTEN)
    target_link_libraries(webgame_render PUBLIC glfw)
endif()

add_library(webgame::render ALIAS webgame_render)

