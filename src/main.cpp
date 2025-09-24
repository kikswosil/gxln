#include <iostream>
#include <fstream>
#include <functional>
#include <regex>
#include "gxln/converters.hpp"
#include "ui/cli.hpp"

// void parseArgs(int argc, char* argv[], std::string& inputFileName, std::string& outputFileName);
// void formatNumbers(std::ifstream& inputFile, std::function<std::string(const std::string)> formatFunc);

// void readfile(std::string filename, std::function<void(std::ifstream&, std::function<std::string(const std::string)>)> callback) {
//     std::ifstream file(filename);
//     if(!file.is_open()) {
//         std::cerr << "Could not find file: " << filename << std::endl;
//         system("exit");
//     }
//     formatNumbers(file, gxln_conv::xlnToGcodeFormat);
//     file.close();
// }

int main(int argc, char* argv[]) {
    UI *ui = new CLI();
    ui->run(argc, argv);
    delete ui;
    // std::string inputFileName = "";
    // std::string outputFileName = "";

    // // find filenames
    // parseArgs(argc, argv, inputFileName, outputFileName);

    // // open input file
    // readfile(inputFileName, formatNumbers); // temporary solution 

    // std::cout << "input: " << inputFileName << ", output: " << outputFileName << std::endl;
    return 0;
}

// void parseArgs(int argc, char* argv[], std::string& inputFileName, std::string& outputFileName) {
//     for (int i = 1; i < argc; i++) {
//         if(std::string(argv[i]) == "-i" && i + 1 < argc) {
//             inputFileName = argv[i + 1];
//         } 
//         else if(std::string(argv[i]) == "-o" && i + 1 < argc) {
//             outputFileName = argv[i + 1];
//         }
//     }
// }

// void formatNumbers(std::ifstream& inputFile, gxln_conv::converter formatFunc) {
//     std::string line;
//     while (std::getline(inputFile, line)) {
//         std::cout << formatFunc(line) << std::endl;
//     }
// }