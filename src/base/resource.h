
#pragma once

#include <webgame.h>

#include <memory>
#include <string>

WEBGAME_NAMESPACE_BEGIN(base)

class resource : public std::enable_shared_from_this<resource> {
public:
    explicit resource(std::string path) : path(path) {};
    virtual ~resource();

    virtual void load() = 0;

private:
    std::string path;
};

WEBGAME_NAMESPACE_END(base)

