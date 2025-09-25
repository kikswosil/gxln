#include "cli.hpp"
#include "../file/filehandler.hpp"
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

std::string CLI::formatNumbers(const std::string &filename, gxln_conv::converter formatFunc) {
    std::ifstream inputFile = FileHandler::openFile(filename);
    
    std::string result = "";
    std::string line;
    while (std::getline(inputFile, line)) {
        result.append(formatFunc(line)).append("\n");
    }
    return result;
}

void CLI::run(int argc, char* argv[]) {
    std::string inputFileName = "";
    std::string outputFileName = "";

    this->parseArgs(argc, argv, inputFileName, outputFileName);

    FileHandler::saveFile(outputFileName, this->formatNumbers(inputFileName, gxln_conv::xlnToGcodeFormat));
}