#include "filehandler.h"
#include <iostream>
#include <ranges>

#include <string_view>
#include <iomanip>


FH::States state;
bool FH::read(path filepath, std::stringstream& buffer )
{
    // Initialize readFile 
    std::ifstream readFile{ filepath, std::ios_base::in };    
    if( !readFile )
    {
        state = States::readError;
        return false;
    }

    buffer.str("");
    buffer.clear();
    
    // Fill the buffer 
    buffer << readFile.rdbuf() ;
    if( readFile.fail() && !readFile.eof() )
    {
        state = States::readError;
        return false;
    }
    readFile.close();
    return true;
}
 
bool FH::write(path filepath, std::string prompt)
{
    // Initialize writeFile 
    std::ofstream writeFile{ filepath, std::ios_base::trunc };    
    if( !writeFile )
    {
        state = States::writeError;
        return false;
    }
    
    writeFile << prompt;
    if( writeFile.fail() )
    {
        state = States::writeError;
        return 0;
    }

    // Finalize
    writeFile.close();
    return true;
}

bool FH::append( path filepath, std::string prompt )
{ 
    // Initialize appendFile 
    std::ofstream appendFile{ filepath, std::ios_base::app };
    if( !appendFile )
    {
        state = States::appendError;
        return false;
    }
    
    appendFile << prompt;
    if( appendFile.fail() )
    {
        state = States::appendError;
        return 0;
    }

    // Finalize
    appendFile.close();
    return true;
}

bool FH::mkdir( path folderPath )
{
    if( !create_directory( folderPath ) )
    {
        return false;
    }
    return true;
}

bool FH::mkdirp( path folderPath ) 
{
    std::stringstream ss; 
    ss << "./";

    // C++ 23 provides an easier "split" method!
    const std::string pathInStr{ folderPath };
    const std::string delimiter{ "/" };
    for(const auto words : std::views::split(pathInStr, delimiter))
    {
        ss << std::string_view(words) << '/';
        if( !exists(ss.str()) ) 
        {
            mkdir( ss.str() );
        }
    }

    return true;
}
