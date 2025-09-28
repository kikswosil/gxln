#pragma once
#include "converters.hpp"

namespace gxln_util {
std::string convert(const std::string &filename,
                    gxln_conv::converter formatFunc);
}
