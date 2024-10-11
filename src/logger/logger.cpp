#include <unordered_map>
#include <string>
#include <filesystem>
#include <iostream>
#include "logger.h"

using namespace std;

// Function Definitions for the Logger class from Logger.h
Logger::Logger() {
    // Intentionally left blank
} 

Logger::~Logger() {
    std::cerr << "THE PROGRAM SHOULD BE TERMINATING";
}

<<<<<<< HEAD
void Logger::addVersion(string& name, filesystem::path init,
                                      filesystem::path end) {
    FH::mkdirp(end / name);
    std::filesystem::copy(init, end / name); 
=======
bool Logger::addVersion(string name, filesystem::path init,
                        filesystem::path end, bool replace) 
{
    // Can't replace existing versions without specifying.
    if ( !replace && std::filesystem::exists(end/name) ) {
        state = Logger::State::errAddExist;
        return false; 
    }

    // Add version 
    FH::mkdirp( end/name );
    FH::copyContents(init, end/name);
    
    return true;
>>>>>>> 51e7c9c15d3a0074d66c7b769c4c9c629bacef1e
}

void Logger::deleteVersion(string name, filesystem::path end) {
    std::filesystem::remove_all( end/name );
}

// Initialize static instance of Logger. 
Logger* Logger::instance = new Logger();



// get the necessary files from a version
void Logger::useVersion(string name, filesystem::path curr
                                , filesystem::path replace ){
    std::filesystem::path from = replace/name;
    FH::dirCpy(from, curr);
}
