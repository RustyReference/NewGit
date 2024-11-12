#include <iostream>
#include "./logger/logger.h"
#include "./logger/filehandler/filehandler.h"
#include <string>
#include <filesystem> 
#include <fstream>

using namespace std;
namespace fs = filesystem;

void gitInitialize();
void gitPull(string version, std::filesystem::path branch);
void gitPush(string versionName, std::filesystem::path branch);
void gitDelete(string versionName, std::filesystem::path branch);
void forcePush(string versionName, std::filesystem::path branch);
void listBranches(std::filesystem::path newgitPath);
void help();
void fizzBuzz();

// Main is responsible for handling params and params only.
int main(int argc, char* argv[]) {
    string prompt;
    if(argc > 3) {
        prompt = "help";
    }

		if(argc <= 1) {
			gitInitialize();
			cout << "Initializing done!" << endl;
			return 0;
		}


    prompt = argv[1];
		// Help
  	if(prompt == "-H") {
			fizzBuzz();}
    else if (prompt == "help") {
			help(); 
			return 0;
		}

		// clean
		if(prompt == "clean") {
			if(std::filesystem::remove_all(".newgit")) {
				cout << "Succesfully cleaned up the newgit from this project" << endl;
			}
			else {
				cerr << "Could not delete the folder '.newgit', check the permissions" << endl;
			}
			return 0;
		}	

		// status
		if(prompt == "status") {
			listBranches("./.newgit/");
			return 0;
		}

		std::stringstream currentBranch;
		if(!FH::read(".newgit/log", currentBranch)) {
			cerr << "Could not read branch" << endl;
			exit(EXIT_FAILURE);
		}
		std::string branch;
		currentBranch >> branch;
		std::filesystem::path branchPath = ".newgit/"+branch;

		if(prompt == "delete") {
			if(!std::filesystem::exists(branchPath)) {
				cerr << "Unexisting branch" << endl;
			}
			else if(std::filesystem::remove_all(branchPath)) {
				cout << "Succesfully deleted the branch " << branch << endl;
			}
			else {
				cerr << "Could not delete the branch, check permissions" << endl;
			}
			return 0;
		}

		if(argc <= 2) {
			help();
			exit(EXIT_FAILURE);
		}
	  std::string version = argv[2];

    // Push
    if(prompt == "push") {
        if(argc < 3) {
            std::cout << "Not enough params!\n";
            help();
        }
        else {
            gitPush(version, branchPath); 
        }
    }

    // Pull
    else if(prompt == "pull") {
        if(argc < 3) {
            std::cout << "Not enough parameters!\n";
            help();
        }
        else {
            gitPull(version, branchPath);
        }
    }

    // Delete
    else if(prompt == "trim") {
        if(argc < 3) {
            std::cout << "Not enough params!\n";
            help();
        }
        else {
          	gitDelete(version, branchPath);
        }
    }

	// Select branch
	else if(prompt == "select") {
		if(argc < 3) {
			std::cout << "Not enough params!\n";
			help();
		}
		else {
			FH::write("./.newgit/log", argv[2]);	
		}
	}

		// forced push
    else if(prompt == "force-push") { 
			forcePush(version, branchPath); 
		}
		
		// pull 
    else if(prompt == "pull") { 
			gitPull(version, branchPath);
		}

    return 0;
}

// Initializes a repository
void gitInitialize() {
		if(std::filesystem::exists(".newgit")) {
			cerr << "This project has already been initialized!" << endl;
			cerr << "Use 'NewGit clean' to remove NewGit completely" << endl;
			exit(EXIT_FAILURE);
		}
		cout << "Intializing main branch" << endl;
		if(!FH::mkdirp(".newgit/main")) {
			cerr << "Could not make the folder. Check permissions" << endl;
		}
		if(!FH::write(".newgit/log", "main\n")) {
			cerr << "Could not make file \'main\'. Check permissions." << endl;
		}
}

// Push changes to a remote repository
void gitPush(string versionName, std::filesystem::path branch) {
    if ( !Logger::getInstance().addVersion(versionName, "./", branch ) ) {
        if(Logger::getInstance().state == Logger::State::errAddExist) {
            cout << "Folder exists. Use \'force-push\' to replace instead\n";
        }
        cout << "Could not add version : " << versionName << endl;
        return;
    }
    cout << "Succesfully added version : " << versionName << endl;
}

void forcePush(string versionName, std::filesystem::path branch) {
    // true at the end = "force"
    gitDelete(versionName, branch);
    if(!Logger::getInstance().addVersion(versionName, "./", branch, true)) {
        cout << "Could not add version : " << versionName << endl;
        return;
    }
    cout << "Succesfully added version : " << versionName << endl;
}

// Pulls changes from a remote repository
void gitPull(string version, std::filesystem::path branch) {
    Logger::getInstance().useVersion(version, "./", branch);
}

// Prints all the possible commands the user can make
void help() {
    cout << "Usage : \n";
    cout << "\tnewgit push <versionName>\n"
            "\tnewgit pull <versionName>\n"
            "\tnewgit force-push <versionName>\n"
						"\tnewgit trim <versionName>\n"
            "\tnewgit select <branchName>\n"
            "\tnewgit delete <branchName>\n"
            "\tnewgit status\n"
            "\tnewgit help\n";
}

// Delete version/folder
void gitDelete(string name, std::filesystem::path branch) {
    Logger::getInstance().deleteVersion(name, branch);
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

void listBranches(std::filesystem::path newgitPath) {
	for(auto dir : std::filesystem::directory_iterator(newgitPath)) {
		if(is_directory(dir)) {
		  cout << dir << endl;
		}
	}
}
