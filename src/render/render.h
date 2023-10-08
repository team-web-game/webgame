
#pragma once

#ifdef __EMSCRIPTEN__
#define GLFW_INCLUDE_GLES3
#else
#include <glad/gl.h>
#endif

#include <GLFW/glfw3.h>

