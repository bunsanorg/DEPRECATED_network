#pragma once

#include <string>
#include <vector>

namespace bunsan{namespace base64
{
    std::string encode(const std::vector<unsigned char> &data);
    std::string encode(const std::string &data);
    std::vector<unsigned char> decode(const std::string &base64);
}}
