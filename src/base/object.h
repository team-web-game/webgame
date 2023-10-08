
#pragma once

#include <webgame.h>

#include <vector>
#include <memory>

WEBGAME_NAMESPACE_BEGIN(base)

class object : public std::enable_shared_from_this<object> {
public: 

    void add_child(std::shared_ptr<object> child);
    void remove_child(std::shared_ptr<object> child);
    void set_parent(std::shared_ptr<object> parent);

    inline std::shared_ptr<object> get_parent() {
        return parent.lock();
    }

private:
    std::vector<std::shared_ptr<object>> children;
    std::weak_ptr<object> parent;
};

WEBGAME_NAMESPACE_END(base)

