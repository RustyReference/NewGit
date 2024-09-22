#include "filehandler.h"
#include <iostream>

FH::States state;

bool FH::read(path filepath, std::stringstream& buffer )
{
    // Initialize readFile 
    std::ifstream readFile{ filepath, std::ios_base::in };    
    if( !readFile )
    {
        std::cerr << "Could not open readFile : " << filepath;
        std::cerr << std::endl;
        state = States::readError;
        return false;
    }

    buffer.str("");
    buffer.clear();
    
    // Fill the buffer 
    buffer << readFile.rdbuf() ;
    if( readFile.fail() && !readFile.eof() )
    {
        std::cerr << "Could not read to buffer : " << filepath; 
        std::cerr << std::endl;
        state = States::readError;
        return false;
    }
    readFile.close();
    state = States::readSuccess;
    return true;
}
 
bool FH::write(path filepath, std::string prompt)
{
    // Initialize writeFile 
    std::ofstream writeFile{ filepath, std::ios_base::trunc };    
    if( !writeFile )
    {
        std::cerr << "Could not open writeFile : " << filepath << std::endl;
        state = States::writeError;
        return false;
    }
    
    writeFile << prompt;
    if( writeFile.fail() )
    {
        std::cerr << "Couldn't write to : " << filepath << '\n';
        state = States::writeError;
        return 0;
    }

    // Finalize
    writeFile.close();
    state = States::writeSuccess;
    return true;
}


