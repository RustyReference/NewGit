
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
    cout << "THE PROGRAM SHOULD BE TERMINATING";
}

bool Logger::addVersion(string name, filesystem::path init,
                        filesystem::path end, bool replace) 
{
    if ( !replace && std::filesystem::exists(end/name) ) {
        state = Logger::State::errAddExist;
        return false; 
    }
    FH::mkdirp( end/name );
    for(auto &entry : std::filesystem::directory_iterator(init)) {
        // Get path name from the last '/'
        // For example "./a/b/c/hello" would turn into hello
        std::string path = entry.path();
        if( path[path.length()] == '/' ) {
            path.pop_back();
        }
        int nameStart = path.rfind('/');
        std::string pathName = path.c_str()+nameStart+1;
        // copy path if it's not the .newgit directory
        if(pathName != ".newgit") {
            std::filesystem::copy(path, end/name
                , std::filesystem::copy_options::recursive);
        }
    }
    return true;
}

void Logger::deleteVersion(string name, filesystem::path end) {
    std::filesystem::remove_all( end/name );
}

Logger* Logger::instance = new Logger();

// Initialize static instance of Logger. 


