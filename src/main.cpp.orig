#include <iostream>
#include "./logger/logger.h"
#include <string>
<<<<<<< HEAD
#include <filesystem> 

=======
#include <filesystem> //Might delete later?
//#include "filehandler.h"
#include "./logger/logger.h"
>>>>>>> refs/remotes/origin/main
using namespace std;
namespace fs = filesystem;

void gitInitialize();
void gitPull();
<<<<<<< HEAD
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
=======
void gitPush();
void help();

int main(int argc, char* argv[]) {
    std::string name = "3.30.4";
    std::filesystem::path init{"./"};
    std::filesystem::path log("./log/");
    Logger::getInstance().addVersion(name, init, log);
    //Logger::getInstance().addVersion(name, ".", "./log/");
    // A TRIAL TEST CASE ONLY: If "test2" does not exist yet, then 
    // it will be created.
    // fs::copy("test", "test2", fs::copy_options::recursive);
}

// Initializes a repository
void gitInitialize(fs::path path) {

}

// Pulls changes from a remote repository
>>>>>>> refs/remotes/origin/main
void gitPull() {
    cout << "Pull";
}

// Pushes changes to a remote repository
void gitPush() {
    cout << "Push";
}

// Prints all the possible commands the user can make
void help() {
    cout << "Help";
}


