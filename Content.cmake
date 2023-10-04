
include(FetchContent)

set(CGLM_SHARED OFF CACHE BOOL "" FORCE)
set(CGLM_STATIC ON CACHE BOOL "" FORCE)

fetchcontent_declare(cglm
    GIT_REPOSITORY https://github.com/recp/cglm.git
    GIT_TAG v0.9.1
)

fetchcontent_makeavailable(cglm)

if(NOT EMSCRIPTEN)
    fetchcontent_declare(glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.3.8
        FIND_PACKAGE_ARGS NAMES glfw3
    )

    fetchcontent_makeavailable(glfw)
elseif()
    find_package(GLFW REQUIRED)
endif()

