#include <unordered_map>
#include <string>
#include <filesystem>

#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

using namespace std;

class Logger {
private:
    static Logger* instance;
    unordered_map<string, filesystem::path> logMap;
    Logger(); 
    ~Logger(); // The Logger should only be destroyed when the program ends

public:
    /**
     * The copy constructor of this class should be deleted
     */
    Logger(const Logger&) = delete;

    /**
     * The assignment operator of this class should be deleted to prevent any 
     * reassignment or change in the static instance.
     */
    Logger& operator= (const Logger&) = delete;

    /**
     * Returns a reference to the singleton instance of the Logger
     */
    static Logger& getInstance() {
        if (!instance) {
            instance = new Logger();
        }

        return *instance;
    }

    /**
     * Adds a version with a name specified by the user to a new folder in a 
     * directory specified by path, copying the files from a user-specified
     * directory to the "log" directory.
     * 
     * name: the name of the update the user specifies
     * init: the path to the directory containing the files/directories
     *       the user wants to copy
     * end: the path to the "log" directory, where all the versions of 
     *      the user's source code are stored.
     */
    void addVersion(string& name, filesystem::path init, filesystem::path end);

    /**
     * Deletes a version (a copy of program files) specified by the user and 
     * located in a directory specified by path.
     * 
     * name: the name of the update the user specifies
     * init: the path to the directory containing the files/directories
     *       the user wants to copy
     * end: the path to the "log" directory, where all the versions of 
     *      the user's source code are stored.
     */
    void deleteVersion(string& name, filesystem::path init, filesystem::path end);

    /**
     * Replaces the files in the current version with the files in the
     * folder specified by "name", effectively backtracking/fastforwarding the 
     * program to a saved version.
     * 
     * name: the name of the update the user specifies
     * curr: the path to the directory containing the current files/directories
     *       of the user's source code.
     * replace: the path to the directory containing the files/directories to
     *          the version of the source code the user wants to
     *          backtrack/fastforward to.
     */
    void useVersion(string& name, filesystem::path curr,
                                  filesystem::path replace);
};

// Initialize static instance of Logger
Logger* Logger::instance = nullptr;

#endif