
#include "app.h"

#include <iostream>
#include <render/render_error.h>

WEBGAME_NAMESPACE_BEGIN(render)

app *current_app = nullptr;

static void glfw_resize(GLFWwindow *win, int w, int h) {
    glViewport(0, 0, w, h);
}

static void glfw_error(int error_code, const char *description) {
    std::cout << "GLFW (0x" << std::hex << error_code << "): " << description << "\n";
}

app::app(int &argc, char *argv[]) : argc(argc), argv(argv) {
    current_app = this;
    glfwSetErrorCallback(glfw_error);

    if (glfwInit() != GLFW_TRUE) {
        throw render_error("GLFW init failed");
    }

    window = glfwCreateWindow(640, 480, "webgame", 0, 0);
    glfwMakeContextCurrent(window);
#ifndef __EMSCRIPTEN__
    gladLoadGL(glfwGetProcAddress);
#endif
    glClearColor(1, 0, 0, 1);

    glfwSetFramebufferSizeCallback(window, glfw_resize);
    glfw_resize(window, 640, 480);
}

void app::generate_frame() {
    glClear(GL_COLOR_BUFFER_BIT);
    
    glfwSwapBuffers(window);
    glfwPollEvents();
}

app &app::get_instance() {
    return *current_app;
}

int app::run() {
#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(...) // TODO
#else
    while (!glfwWindowShouldClose(window)) {
        generate_frame();
    }
#endif

    glfwTerminate();
    return 0;
}

void app::set_title(const char *string) {
    glfwSetWindowTitle(window, string);
}

WEBGAME_NAMESPACE_END(render)

