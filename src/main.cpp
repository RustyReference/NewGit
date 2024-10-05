#include <iostream>
#include <string>
#include <filesystem> //Might delete later?
//#include "filehandler.h"
using namespace std;
namespace fs = filesystem;

void gitInitialize();
void gitPull();
void gitPush();

int main(int argc, char* argv[]) {
    // A TRIAL TEST CASE ONLY: If "test2" does not exist yet, then 
    // it will be created.
    fs::copy("test", "test2", fs::copy_options::recursive);
}

// Initializes a repository
void gitInitialize() {

}

// Pulls changes from a remote repository
void gitPush() {
    
}

// Pulls changes from a remote repository
void gitPull() {
    string name;
    cout << "Enter the name of your new version: ";
    cin >> name;
}

