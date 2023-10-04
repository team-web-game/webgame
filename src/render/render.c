
#include "render.h"

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

GLFWwindow *r_window = NULL;

static void r_handle_glfw_error(int error_code, const char *description) {
    printf("GLFW (0x%.04x: %s", error_code, description);
}

void r_open_context() {
    glfwSetErrorCallback(r_handle_glfw_error);

    if (glfwInit() != GLFW_TRUE) {
        b_force_exit(EXIT_FAILURE);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    r_window = glfwCreateWindow(640, 480, "Webgame", NULL, NULL);
    if (r_window == NULL) {
        fprintf(stderr, "GLFW init failure");
        glfwTerminate();
        b_force_exit(EXIT_FAILURE);
    }

    glfwMakeContextCurrent(r_window);
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(r_generate_frame, 0, false);
#else
    while (!glfwWindowShouldClose(r_window)) {
        r_frame();
    }

    glfwTerminate();
#endif
}

void r_frame() {
    glfwSwapBuffers(r_window);
    glfwPollEvents();
}

