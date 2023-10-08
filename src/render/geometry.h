
#pragma once

#include <webgame.h>
#include <base/object.h>

#include "render/mesh.h"

WEBGAME_NAMESPACE_BEGIN(render)

class geometry : public base::object {
public:

private:
    std::shared_ptr<mesh> mesh;
};

WEBGAME_NAMESPACE_END(render)

