#include "utilities.hpp"
#include <fstream>
#include <string>

namespace gxln_util {
    std::string convert(const std::string &filename, gxln_conv::converter formatFunc) {
        std::ifstream inputFile(filename);
        std::string result = "";
        std::string line = "";
        while (std::getline(inputFile, line)) {
            result.append(formatFunc(line)).append("\n");
        }
        return result;
    }
}