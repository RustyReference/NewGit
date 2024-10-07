#include <iostream>
#include <string>
#include <filesystem> //Might delete later?
//#include "filehandler.h"
#include "logger.h"
using namespace std;
namespace fs = filesystem;

void gitInitialize();
void gitPull();
void gitPush();
void help();

int main(int argc, char* argv[]) {
    if (strcmp(argv[0], "-h")) {
        help();
    } else {
        if (fs::is_directory(argv[0])) {
            Logger::getInstance().setRepoPath(argv[0]);
        } else {
            fs::create_directory(argv[0]);
            Logger::getInstance().setRepoPath(argv[0]);
        }
    }
}

// Initializes a repository
void gitInitialize(fs::path path) {
    Logger::getInstance().setRepoPath(path);
}

// Pulls changes from a remote repository
void gitPull() {
    cout << "Pull";
}

// Pushes changes to a remote repository
void gitPush() {
    cout << "Push"
}

// Prints all the possible commands the user can make
void help() {
    cout << "Help";
}


