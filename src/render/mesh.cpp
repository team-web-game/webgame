
#include "mesh.h"

WEBGAME_NAMESPACE_BEGIN(render)

mesh::mesh(std::string path) : base::resource(path) {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
}

mesh::~mesh() {
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}

WEBGAME_NAMESPACE_END(render)

