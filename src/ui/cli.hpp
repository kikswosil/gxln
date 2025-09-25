#pragma once
#include "ui.hpp"
#include "../gxln/converters.hpp"
#include <string>
#include <fstream>

class CLI : public UI {
    private: 
        void parseArgs(int argc, char *argv[], std::string &inputFileName, std::string &outputFileName);
        std::string formatNumbers(const std::string &inputFile, gxln_conv::converter formatFunc);
        std::ifstream openFile(const std::string& fileName);
        void saveFile(const std::string &fileName, const std::string &content);
        void fileIsolator(const std::string &inputFileName, const std::string &outputFileName);
    public:
        void run(int argc, char *argv[]) override;
};