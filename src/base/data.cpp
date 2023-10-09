
#include "data.h"

WEBGAME_NAMESPACE_BEGIN(base)

const std::pair<const char *, data_protocol> protocols[] = {
    { "res://", data_protocol::res },
    { "https://", data_protocol::https },
    { "file://", data_protocol::file },
    { "local://", data_protocol::local },
    { "global://", data_protocol::global },
};

data_protocol protocol_guess(const std::string &path) {
    for (int i = 0; i < 5; i++) {
        auto &protocol = protocols[i];
        if (path.rfind(protocol.first, 0) == 0) {
            return protocol.second;
        }
    }
    return data_protocol::invalid;
}

std::string_view data_read(const std::string &path) {
    
}

WEBGAME_NAMESPACE_END(base)

