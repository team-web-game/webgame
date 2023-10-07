
#ifndef RENDER_H_
#define RENDER_H_

#ifdef __EMSCRIPTEN__
#define GLFW_INCLUDE_ES3
#else
#include <glad/gl.h>
#endif

#include <webgame.h>
#include <GLFW/glfw3.h>

extern GLFWwindow *r_window;

void r_open_context();

#endif // RENDER_H_
