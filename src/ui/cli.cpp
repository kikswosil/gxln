#include "cli.hpp"
#include <iostream>

void CLI::parseArgs(int argc, char* argv[], std::string& intputFileName, std::string& outputFileName) {
    for (int i = 1; i < argc; i++) {
        if(std::string(argv[i]) == "-i" && i + 1 < argc) {
            intputFileName = argv[i + 1];
        } 
        else if(std::string(argv[i]) == "-o" && i + 1 < argc) {
            outputFileName = argv[i + 1];
        }
    }
}

void CLI::formatNumbers(std::ifstream& inputFile, gxln_conv::converter formatFunc) {
    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << formatFunc(line) << std::endl;
    }
}

void CLI::run(int argc, char* argv[]) {
    std::string inputFileName = "";
    std::string outputFileName = "";
    this->parseArgs(argc, argv, inputFileName, outputFileName);

    std::ifstream inputFile(inputFileName);

    if (!inputFile.is_open()) {
        std::cerr << "Error opening files!" << std::endl;
        return;
    }
    this->formatNumbers(inputFile, gxln_conv::xlnToGcodeFormat);
}