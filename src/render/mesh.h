
#pragma once

#include <webgame.h>
#include <base/resource.h>
#include <cstdint>

#include <glm/glm.hpp>

#include "render.h"

WEBGAME_NAMESPACE_BEGIN(render)

struct mesh_vertex_tiny {
    glm::vec3 pos;
};

class mesh : public base::resource {
public:
    explicit mesh(std::string path);
    ~mesh();

    inline void bind() {
        glBindVertexArray(vao);
    }

private:
    uint32_t vao;
    uint32_t vbo;
};

WEBGAME_NAMESPACE_END(render)

