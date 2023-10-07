
add_library(glad_glad STATIC
    src/gl.c
)
target_include_directories(glad_glad PUBLIC include)

add_library(glad::glad ALIAS glad_glad)

