#include "filehandler.hpp"

FileHandler::FileHandler() {}
FileHandler::~FileHandler() {}


std::ifstream FileHandler::openFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file: " + filename);
    }
    return file;    
}

void FileHandler::saveFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for writing: " + filename);
    }
    file << content;
    file.close();
}