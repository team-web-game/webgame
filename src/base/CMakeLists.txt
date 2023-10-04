
add_library(webgame_base STATIC
    base.c
)
target_include_directories(webgame_base PUBLIC ..)

add_library(webgame::base ALIAS webgame_base)

