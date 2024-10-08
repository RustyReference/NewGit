#include <iostream>
#include "./logger/logger.h"
#include <string>
#include <filesystem> 

using namespace std;
namespace fs = filesystem;

void gitInitialize();
void gitPull();
void gitPush(std::string versionName);

int main(int argc, char* argv[]) {
    gitInitialize();
    gitPush("testversion");
    //std::filesystem::path init{"./"};
    //std::filesystem::path log("./log/");
    //Logger::getInstance().deleteVersion("3.30.4", "./log");
    return 0;
}

// Initializes a repository
void gitInitialize() {
    FH::mkdirp(".newgit/log/");
}

// Pulls changes from a remote repository
void gitPush(std::string versionName) {
    if ( !Logger::getInstance().addVersion(versionName, "./", "./.newgit/log/") ) {
        if(Logger::getInstance().state == Logger::State::errAddExist) {
            std::cout << "Folder exists. Use \'force-push\' to replace instead\n";
        }
        std::cout << "Could not add version : " << versionName << std::endl;
        return;
    }
    std::cout << "Succesfully added version : " << versionName << std::endl;
}

void forcePush(std::string versionName) {
    // true at the end = "force"
    if(!Logger::getInstance().addVersion(versionName, "./", "./.newgit/log", true)) {
        std::cout << "Could not add version : " << versionName << std::endl;
        return;
    }
    std::cout << "Succesfully added version : " << versionName << std::endl;
}

// Pulls changes from a remote repository
void gitPull() {
    string name;
    cout << "Enter the name of your new version: ";
    cin >> name;
}

