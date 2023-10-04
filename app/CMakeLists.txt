
add_executable(webgame_app
    main.c
)
target_link_libraries(webgame_app PUBLIC webgame::script webgame::render)

