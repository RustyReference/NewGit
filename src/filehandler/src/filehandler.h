#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <fstream>
#include <filesystem>
#include <string_view>
#include <sstream>

// To keep record of the current state of the FileHandler class.
enum States
{
    readSuccess,
    readError,
    readEmpty,
    writeSuccess,
    writeError
};

class FileHandler 
{
    public:
    FileHandler();  
    ~FileHandler(); 
    
    // Reads a file and puts it into the buffer. Return false on fail.
    bool read(std::filesystem::path filepath, std::stringstream& buffer );    
    // Writes a given string to a given filepath.  
    bool write( std::filesystem::path filepath, std::string prompt); 
    
    // Keeps record of errors etc.
    States currentState;
};

#endif
