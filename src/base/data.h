
#pragma once

#include <webgame.h>

#include <cstdint>
#include <string>

WEBGAME_NAMESPACE_BEGIN(base)

enum class data_protocol : uint8_t {
    invalid, // no protocol present/not valid protocol
    res, // read-only: game data location
    https, // read-only: download from internet
    file, // read-write: user file
    local, // read-write: local game working folder
    global, // read-write: working folder shared between all games
};

data_protocol protocol_guess(const std::string &path);
std::string_view data_read(const std::string &path);

WEBGAME_NAMESPACE_END(base)

