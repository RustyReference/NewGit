#include <iostream>
#include "./logger/logger.h"
#include "./logger/filehandler/filehandler.h"
#include <string>
#include <filesystem> 
#include <fstream>

using namespace std;
namespace fs = filesystem;

void gitInitialize();
void gitPull(string version);
void gitPush(string versionName);
void gitDelete(string versionName);
void forcePush(string versionName);
void help();

// Main is responsible for handling params and params only.
int main(int argc, char* argv[]) {
    string prompt;
    if(argc <= 1 || argc > 3) {
        prompt = "help";
    }
    else {
        prompt = argv[1];
    }

    // Push
    if(prompt == "push") {
        if(argc < 3) {
            std::cout << "Not enough params!\n";
            help();
        }
        else {
            gitPush(argv[2]); 
        }
    }

    // Pull
    else if(prompt == "pull") {
        if(argc < 3) {
            std::cout << "Not enough parameters!\n";
            help();
        }
        else {
            gitPull(argv[2]);
        }
    }

    // Delete
    else if(prompt == "delete") {
        if(argc < 3) {
            std::cout << "Not enough params!\n";
            help();
        }
        else {
            gitDelete(argv[2]);
        }
    }

    else if(prompt == "force-push"){ forcePush(argv[2]); }
    else if(prompt == "pull"){ }
    else if(prompt == "-H") {fizzBuzz();}
    else{ help(); }


    return 0;
}

// Initializes a repository
void gitInitialize() {
    FH::mkdirp(".newgit/log/");
}

// Pulls changes from a remote repository
void gitPush(string versionName) {
    if ( !Logger::getInstance().addVersion(versionName, "./", "./.newgit/log/") ) {
        if(Logger::getInstance().state == Logger::State::errAddExist) {
            cout << "Folder exists. Use \'force-push\' to replace instead\n";
        }
        cout << "Could not add version : " << versionName << endl;
        return;
    }
    cout << "Succesfully added version : " << versionName << endl;
}

void forcePush(string versionName) {
    // true at the end = "force"
    gitDelete(versionName);
    if(!Logger::getInstance().addVersion(versionName, "./", "./.newgit/log", true)) {
        cout << "Could not add version : " << versionName << endl;
        return;
    }
    cout << "Succesfully added version : " << versionName << endl;
}

// Pulls changes from a remote repository
void gitPull(string version) {
    fs::path logPath = fs::path("./.newgit/log");
    Logger::getInstance().useVersion(version, "./", logPath);
}

// Prints all the possible commands the user can make
void help() {
    cout << "Usage : \n";
    cout << "\tnewgit push <versionName>\n"
            "\tnewgit pull <versionName>\n"
            "\tnewgit force-push <versionName>\n"
            "\tnewgit help\n";
}

// Delete version/folder
void gitDelete(string name) {
    Logger::getInstance().deleteVersion(name, "./.newgit/log/");
}

//FizzBuzz easter egg
void fizzBuzz() {
    for (int i = 0; i < 200; i++) {
        if (i % 3 == 0)
            cout << "Fizz";
        if (i % 5 == 0) 
            cout << "Buzz";
        cout << endl;
    }
}
