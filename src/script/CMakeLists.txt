
add_library(webgame_script STATIC
    script.cpp
)
target_include_directories(webgame_script PUBLIC ..)
target_link_libraries(webgame_script PUBLIC lua::lua webgame::base)

add_library(webgame::script ALIAS webgame_script)

