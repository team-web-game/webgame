
include(FetchContent)

fetchcontent_declare(glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG 8b94f970d9666f77f4400103e31aaa4a79a7edef
)

fetchcontent_makeavailable(glm)

if(NOT EMSCRIPTEN)
    fetchcontent_declare(glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.3.8
        FIND_PACKAGE_ARGS NAMES glfw3
    )

    fetchcontent_makeavailable(glfw)
endif()

