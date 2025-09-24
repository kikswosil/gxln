#include <iostream>
#include <fstream>
#include <functional>
#include <regex>

void parseArgs(int argc, char* argv[], std::string& inputFileName, std::string& outputFileName);
void formatNumbers(std::ifstream& inputFile, std::function<std::string(const std::string)> formatFunc);
std::string xlnToGcodeFormat(std::string line);

void readfile(std::string filename, std::function<void(std::ifstream&, std::function<std::string(const std::string)>)> callback) {
    std::ifstream file(filename);
    if(!file.is_open()) {
        std::cerr << "Could not find file: " << filename << std::endl;
        system("exit");
    }
    formatNumbers(file, xlnToGcodeFormat);
    file.close();
}

int main(int argc, char* argv[]) {
    std::string inputFileName = "";
    std::string outputFileName = "";
    // std::string _;

    // find filenames
    parseArgs(argc, argv, inputFileName, outputFileName);

    // open input file
    std::cout << "output: " << outputFileName << std::endl;
    // std::ifstream inputFile(inputFileName, std::ios::in);
    readfile(inputFileName, formatNumbers); // temporary solution 
    std::cout << "output: " << outputFileName << std::endl;
    // // handle file open error
    // if (!inputFile.is_open()) {
    //     std::cerr << "Error opening input file: " << inputFileName << std::endl;
    //     return 1;
    // }
    // // format numbers in the file
    // formatNumbers(inputFile, xlnToGcodeFormat);
    // close file
    // inputFile.close();

    std::cout << "input: " << inputFileName << ", output: " << outputFileName << std::endl;
    return 0;
}

void parseArgs(int argc, char* argv[], std::string& inputFileName, std::string& outputFileName) {
    for (int i = 1; i < argc; i++) {
        std::cout << argv[i] << std::endl;
        if(std::string(argv[i]) == "-i" && i + 1 < argc) {
            inputFileName = argv[i + 1];
            // ++i;
        } 
        else if(std::string(argv[i]) == "-o" && i + 1 < argc) {
            outputFileName = argv[i + 1];
            // ++i;
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