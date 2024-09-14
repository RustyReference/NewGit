#include "filehandler.h"
#include <iostream>

FileHandler::FileHandler(){}
FileHandler::~FileHandler(){}

bool FileHandler::
read(std::filesystem::path filepath, std::stringstream& buffer )
{
    // Initialize readFile 
    std::ifstream readFile{ filepath, std::ios_base::in };    
    if( !readFile )
    {
        std::cerr << "Could not open readFile : " << filepath << std::endl;
        currentState = States::readError;
        return false;
    }

    buffer.str("");
    buffer.clear();
    
    // Fill the buffer 
    buffer << readFile.rdbuf() ;
    if( readFile.fail() && !readFile.eof() )
    {
        std::cerr << "Could not read to buffer : " << filepath << std::endl;
        currentState = States::readError;
        return false;
    }
    readFile.close();
    currentState = States::readSuccess;
    return true;
}
 
bool FileHandler::
write(std::filesystem::path filepath, std::string prompt)
{
    // Initialize writeFile 
    std::ofstream writeFile{ filepath, std::ios_base::trunc };    
    if( !writeFile )
    {
        std::cerr << "Could not open writeFile : " << filepath << std::endl;
        currentState = States::writeError;
        return false;
    }
    
    writeFile << prompt;
    if( writeFile.fail() )
    {
        std::cerr << "Couldn't write to : " << filepath << '\n';
        currentState = States::writeError;
        return 0;
    }

    // Finalize
    writeFile.close();
    currentState = States::writeSuccess;
    return true;
}
