#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <fstream>
#include <sstream>
#include <string_view>

// To keep record of the current state of the FileHandler class.
enum currentState
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
    
    // Reads a file and puts it into the buffer. Sets state accordingly.
    void readFile( std::string_view filepath );   
    // Writes string to a given filepath.
    void writeFile( std::string_view val, std::string_view filepath ); 

    private:
    std::stringstream* FILEBUFF;
    currentState state;
};

#endif
