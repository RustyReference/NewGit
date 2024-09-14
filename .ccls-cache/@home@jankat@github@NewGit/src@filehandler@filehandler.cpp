#include "filehandler.h"
#include <iostream>

FileHandler::FileHandler(){}
FileHandler::~FileHandler(){}

void FileHandler::
read(std::filesystem::path filepath
            , std::stringstream& buffer )
{
    // Initialize readFile 
    std::fstream readFile{ filepath };    
    if( !readFile )
    {
        std::cerr << "Could not open readFile : " << filepath << std::endl;
        currentState = States::readError;
        return;
    }
    
    // Read from file into buffer one line at a time.
    std::string temp;
    while( std::getline(readFile, temp))
    {
        buffer << temp << '\n';
    }

    // Check empty 
    if( buffer.rdbuf()->in_avail() == 0 )
    {
        currentState = States::readEmpty;
    }

    // Finalize
    readFile.close();
    currentState = States::readSuccess;
}
 
void FileHandler::
write( std::string prompt
, std::filesystem::path filepath)
{
    // Initialize writeFile 
    std::fstream writeFile{ filepath };    
    if( !writeFile )
    {
        std::cerr << "Could not open readFile : " << filepath << std::endl;
        currentState = States::writeError;
        return;
    }
    
    // Read from file into buffer one line at a time.
    std::istringstream iss{ prompt };
    std::string temp;
    while( std::getline(iss, temp) )
    {
        writeFile << temp << "\n";
    }

    // Finalize
    writeFile.close();
    currentState = States::writeSuccess;
}

