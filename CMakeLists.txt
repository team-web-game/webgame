cmake_minimum_required(VERSION 3.21)

project(webgame
    VERSION 0.1.0
    LANGUAGES C
)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

if(EMSCRIPTEN)
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
endif()

include(Content.cmake)

add_subdirectory(extern/lua)
add_subdirectory(extern/glad)

add_subdirectory(src/base)
add_subdirectory(src/render)
add_subdirectory(src/script)

add_subdirectory(app)

