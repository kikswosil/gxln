#include "cli.hpp"
#include "../file/filehandler.hpp"
#include "../gxln/utilities.hpp"
#include <iostream>

void CLI::parseArgs(int argc, char *argv[], CLISettings &settings) {
    for(int i = 1; i < argc; i++) {
        if(std::string(argv[i]) == "-i" && i + 1 < argc) {
            settings.inputFile = argv[i + 1];
        }
        else if(std::string(argv[i]) == "-o" && i + 1 < argc) {
            settings.outputFile = argv[i + 1];
        }
    }
}

void CLI::run(int argc, char* argv[]) {
    CLISettings settings;

    this->parseArgs(argc, argv, settings);

    std::string converted = gxln_util::convert(settings.inputFile, gxln_conv::xlnToGcodeFormat);

    FileHandler::saveFile(settings.outputFile, converted);
}