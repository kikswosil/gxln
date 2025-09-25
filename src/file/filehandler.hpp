#pragma once

#include <fstream>
#include <string>

class FileHandler {
     public: 
        FileHandler();
        ~FileHandler();

        static std::ifstream openFile(const std::string& filename);
        static void saveFile(const std::string& filename, const std::string& content);
};