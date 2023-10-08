
#pragma once

#include <webgame.h>
#include <vector>

#include "render/mesh.h"

WEBGAME_NAMESPACE_BEGIN(render)

class app {
public:
    explicit app(int &argc, char *argv[]);

    app &get_instance();
    void generate_frame();
    int run();
    void set_title(const char *string);

    inline GLFWwindow *get_window() {
        return window;
    }

private: 
    GLFWwindow *window;

    std::vector<std::weak_ptr<mesh>> meshes;

    int &argc;
    char **argv;

};

extern app *current_app;

WEBGAME_NAMESPACE_END(render)

