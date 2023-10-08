
#pragma once

#include <webgame.h>
#include <stdexcept>

WEBGAME_NAMESPACE_BEGIN(render)

class render_error : public std::runtime_error {
public:
    explicit render_error(const char *msg) : std::runtime_error(msg) {}

};

WEBGAME_NAMESPACE_END(render)

