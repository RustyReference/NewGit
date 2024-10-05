#include <unordered_map>
#include <string>
#include <filesystem>
#include "logger.h"

using namespace std;

// Function Definitions for the Logger class from Logger.h
Logger::Logger() {
    // Intentionally left blank
} 

Logger::~Logger() {
    //cout << "THE PROGRAM SHOULD BE TERMINATING";
}

void Logger::addVersion(string& name, filesystem::path init,
                                      filesystem::path end) {
    
}

void Logger::deleteVersion(string& name, filesystem::path init,
                                         filesystem::path end) {

}


// Initialize static instance of Logger
Logger* Logger::instance = nullptr;