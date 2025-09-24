#pragma once
#include "ui.hpp"
#include "../gxln/converters.hpp"
#include <string>
#include <fstream>

class CLI : public UI {
    private: 
        void parseArgs(int argc, char* argv[], std::string& inputFileName, std::string& outputFileName);
        void formatNumbers(std::ifstream& inputFile, gxln_conv::converter formatFunc);
    public:
        void run(int argc, char* argv[]) override;
};