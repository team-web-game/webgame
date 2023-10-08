
#include "object.h"

#include <memory>
#include <webgame.h>

WEBGAME_NAMESPACE_BEGIN(base)

void object::add_child(std::shared_ptr<object> child) {
    if (auto old_parent = child->parent.lock()) {
        old_parent->remove_child(child);
    }
    children.push_back(child);
    child->parent = weak_from_this();
}

void object::remove_child(std::shared_ptr<object> child) {
    for (int i = 0; i < children.size(); i++) {
        if (children[i] == child) {
            children.erase(children.begin() + i);
            child->parent = std::weak_ptr<object>();
            break;
        }
    }
}

void object::set_parent(std::shared_ptr<object> parent) {
    if (auto old_parent = this->parent.lock()) {
        old_parent->remove_child(shared_from_this());
    }
    this->parent = parent;
}

WEBGAME_NAMESPACE_END(base)

