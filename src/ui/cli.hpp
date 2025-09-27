#pragma once
#include "ui.hpp"
#include "../gxln/converters.hpp"
#include <string>
#include <fstream>

struct CLISettings {
    std::string inputFile;
    std::string outputFile;
};


class CLI : public UI {
    private: 
        void parseArgs(int argc, char *argv[], CLISettings &settings);
    public:
        void run(int argc, char *argv[]) override;
};