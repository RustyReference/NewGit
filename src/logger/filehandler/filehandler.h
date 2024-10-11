#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <fstream>
#include <filesystem>
#include <string_view>
#include <sstream>

using namespace std::filesystem;

namespace FH
{
    // To keep record of the current state of the FileHandler class.
    enum States
    {
        readError,
        readEmpty,
        writeError,
        appendError,
        copyError,
    };

    void dirCpy( path &from, path &to );
    bool read( path filepath, std::stringstream& buffer );
    bool write( path filepath, std::string prompt); 
    bool append( path filepath, std::string prompt );
    bool mkdir( path folderPath );
    bool mkdirp( path folderPath );
    void copyContents( path from, path to );
}

#endif
