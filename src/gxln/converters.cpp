#include "converters.hpp"
#include <regex>

namespace gxln_conv {
std::string xlnToGcodeFormat(std::string line) {
  std::regex *find = new std::regex("^X(\\d+)(\\d\\d)Y(\\d+)(\\d\\d)");
  std::string replace = "G1 X$1.$2Y$3.$4Z-2.00";
  std::string result = std::regex_replace(line, *find, replace);

  find = new std::regex("^G1 X(\\d+).(\\d\\d)Y(\\d+).(\\d\\d)Z-2.00");
  replace = "G0 Z5\rG0 X$1.$2Y$3.$4\rG0 Z0\rG1 F400 X$1.$2Y$3.$4Z-2.00\rG1 "
            "F1000 X$1.$2Y$3.$4Z-2.00\r";
  result = std::regex_replace(result, *find, replace);

  // TODO: make this replace speeds detected in file with user-given speeds.

  delete find;
  return result;
}
} // namespace gxln_conv
