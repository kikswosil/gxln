#pragma once
#include <string>
#include <functional>

namespace gxln_conv {
    typedef std::function<std::string(std::string)> converter;
    std::string xlnToGcodeFormat(std::string line);
}