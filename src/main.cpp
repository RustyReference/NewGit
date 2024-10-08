#include <iostream>
#include "./logger/logger.h"
#include <string>
#include <filesystem> //Might delete later?
//#include "filehandler.h"
#include "./logger/logger.h"
using namespace std;
namespace fs = filesystem;

void gitInitialize();
void gitPull();
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


