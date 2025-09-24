#include <regex>
#include "converters.hpp"

std::string xlnToGcodeFormat(std::string line) {
    std::regex find("^X(\\d+)(\\d\\d)Y(\\d+)(\\d\\d)");
    std::string replace = "G1 X$1.$2Y$3.$4Z-2.00";
    return std::regex_replace(line, find, replace);
}