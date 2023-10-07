
#include "render.h"

#ifdef __EMSCRIPTEN__
#include <emscripten/emscripten.h>
#endif

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>

GLFWwindow *r_window = NULL;

static uint32_t triangle_vao = 0;
static uint32_t triangle_vbo = 0;

static void r_handle_glfw_error(int error_code, const char *description) {
    printf("GLFW (0x%.04x: %s", error_code, description);
}

static void r_frame() {
    glBindVertexArray(triangle_vao);
    glDrawArrays(GL_TRIANGLES, 0, 3);

    glfwSwapBuffers(r_window);
    glfwPollEvents();
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
#ifndef __EMSCRIPTEN__
    gladLoadGL(glfwGetProcAddress);
#endif
    glClearColor(1.0f, 0.0f, 0.0f, 1.0f);

    const float triangle[] = {
        0.0, 0.5, 0.0,
        -0.5, -0.5, 0.0,
        0.5, -0.5, 0.0,
    };

    glGenVertexArrays(1, &triangle_vao);
    glGenBuffers(1, &triangle_vbo);

    glBindVertexArray(triangle_vao);
    glBindBuffer(GL_ARRAY_BUFFER, triangle_vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(triangle), triangle, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 3, NULL);
    glEnableVertexAttribArray(0);

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(r_frame, 0, 0);
#else
    while (!glfwWindowShouldClose(r_window)) {
        r_frame();
    }

    glfwTerminate();
#endif
}

