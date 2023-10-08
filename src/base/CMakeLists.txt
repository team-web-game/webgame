
add_library(webgame_base STATIC
    data.h
    object.cpp
    object.h
    resource.h
    tree.h
)
target_include_directories(webgame_base PUBLIC ..)
target_link_libraries(webgame_base PUBLIC glm::glm)

add_library(webgame::base ALIAS webgame_base)

