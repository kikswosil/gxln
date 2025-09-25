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
    // if(!inputFile.is_open()) {
    //     std::cerr << "Input file is not open!" << std::endl;
    //     return "";
    // }
    std::string result = "";
    std::string line;
    while (std::getline(inputFile, line)) {
        result.append(formatFunc(line)).append("\n");
    }
    return result;
}

// std::ifstream CLI::openFile(const std::string& fileName) {
//     std::ifstream inputFile(fileName);
//     if (!inputFile.is_open()) {
//         std::cerr << "Error opening input file!" << std::endl;
//     }
//     return inputFile;
// }

// void CLI::saveFile(const std::string& fileName, const std::string& content) {
//     std::ofstream outputFile(fileName);
//     if (!outputFile.is_open()) {
//         std::cerr << "Error opening output file!" << std::endl;
//         return;
//     }
//     outputFile << content;
//     outputFile.close();
// }

// void CLI::fileIsolator(const std::string& inputFileName, const std::string& outputFileName) {
//     std::ifstream inputFile = this->openFile(inputFileName);
//     std::string formatted = this->formatNumbers(inputFile, gxln_conv::xlnToGcodeFormat);
//     this->saveFile(outputFileName, formatted);
// }

void CLI::run(int argc, char* argv[]) {
    std::string inputFileName = "";
    std::string outputFileName = "";

    this->parseArgs(argc, argv, inputFileName, outputFileName);

    FileHandler::saveFile(outputFileName, this->formatNumbers(inputFileName, gxln_conv::xlnToGcodeFormat));
}