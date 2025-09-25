#include "cli.hpp"
#include "../file/filehandler.hpp"
#include "../gxln/utilities.hpp"
#include <iostream>

void CLI::parseArgs(int argc, char* argv[], std::string& inputFileName, std::string& outputFileName) {
    for (int i = 1; i < argc; i++) {
        if(std::string(argv[i]) == "-i" && i + 1 < argc) {
            inputFileName = argv[i + 1];
        } 
        else if(std::string(argv[i]) == "-o" && i + 1 < argc) {
            outputFileName = argv[i + 1];
        }
    }
}

void CLI::run(int argc, char* argv[]) {
    std::string inputFileName = "";
    std::string outputFileName = "";

    this->parseArgs(argc, argv, inputFileName, outputFileName);

    // std::string converted = this->convertCoordinates(inputFileName, gxln_conv::xlnToGcodeFormat);
    std::string converted = gxln_util::convert(inputFileName, gxln_conv::xlnToGcodeFormat);

    FileHandler::saveFile(outputFileName, converted);
}