
include(FetchContent)

fetchcontent_declare(cglm
    GIT_REPOSITORY https://github.com/recp/cglm.git
    GIT_TAG v0.9.1
)

fetchcontent_declare(glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG 3.3.8
    FIND_PACKAGE_ARGS NAMES glfw3
)

fetchcontent_makeavailable(cglm glfw)

