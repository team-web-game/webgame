
#pragma once

#include <webgame.h>
#include "render.h"

WEBGAME_NAMESPACE_BEGIN(render)

class App {
public:
    explicit App(int &argc, char *argv[]);

private: 
    GLFWwindow *window;

    int &argc;
    char *argv[];
};

extern App *app;

WEBGAME_NAMESPACE_END(render)

