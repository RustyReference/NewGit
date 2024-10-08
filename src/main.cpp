#include <iostream>
#include "./logger/logger.h"
#include <string>
#include <filesystem> 

using namespace std;
namespace fs = filesystem;

void gitInitialize();
void gitPull();
void gitPush(string versionName);
void help();

int main(int argc, char* argv[]) {
    string prompt;
    if(argc <= 1 || argc > 3) {
        prompt = "help";
    }
    else {
        prompt = argv[1];
    }

    if(prompt == "push"){
        gitPush(argv[2]);
    }

    if(prompt == "help"){
        help();
    }


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
    if(!Logger::getInstance().addVersion(versionName, "./", "./.newgit/log", true)) {
        cout << "Could not add version : " << versionName << endl;
        return;
    }
    cout << "Succesfully added version : " << versionName << endl;
}

// Pulls changes from a remote repository
void gitPull() {
    string name;
    cout << "Enter the name of your new version: ";
    cin >> name;
}

// Prints all the possible commands the user can make
void help() {
    cout << "Usage : \n";
    cout << "\tnewgit push <versionName>\n"
            "\tnewgit pull <versionName>\n"
            "\tnewgit force-push <versionName>\n"
            "\tnewgit help\n";
}

