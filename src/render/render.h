
#ifndef RENDER_H_
#define RENDER_H_

#ifdef __EMSCRIPTEN__
#define GLFW_INCLUDE_ES3
#endif

#include <webgame.h>
#include <GLFW/glfw3.h>

extern GLFWwindow *r_window;

void r_open_context();
void r_frame();

#endif // RENDER_H_
