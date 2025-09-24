#include <iostream>
#include <fstream>
#include <functional>
#include <regex>

void parseArgs(int argc, char* argv[], std::string& inputFileName, std::string& outputFileName);
void formatNumbers(std::ifstream& inputFile, std::function<std::string(const std::string)> formatFunc);
std::string xlnToGcodeFormat(std::string line);

int main(int argc, char* argv[]) {
    std::string inputFileName, outputFileName;


    parseArgs(argc, argv, inputFileName, outputFileName);

    // open input file
    std::ifstream inputFile(inputFileName);
    // handle file open error
    if (!inputFile) {
        std::cerr << "Error opening input file: " << inputFileName << std::endl;
        return 1;
    }
    // format numbers in the file
    formatNumbers(inputFile, xlnToGcodeFormat);
    // close file
    inputFile.close();

    std::cout << "input: " << inputFileName << ", output: " << outputFileName << std::endl;
    return 0;
}

void parseArgs(int argc, char* argv[], std::string& inputFileName, std::string& outputFileName) {
    for (int i = 0; i < argc; ++i) {
        if(std::string(argv[i]) == "-i" && i + 1 < argc) {
            inputFileName = argv[i + 1];
        } else if(std::string(argv[i]) == "-o" && i + 1 < argc) {
            outputFileName = argv[i + 1];
        }
    }
}

void formatNumbers(std::ifstream& inputFile, std::function<std::string(const std::string)> formatFunc) {
    std::cout << "formatting numbers..." << std::endl;
    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << formatFunc(line) << std::endl;
    }
}

std::string xlnToGcodeFormat(std::string line) {
    std::regex find("^X(\\d+)(\\d\\d)Y(\\d+)(\\d\\d)");
    std::string replace = "G1 X$1.$2Y$3.$4Z-2.00";
    return std::regex_replace(line, find, replace);
}