#include "../src/filehandler.h"
#include <fstream>
#include <sstream>
#include <filesystem>
#include <iostream>

int main()
{
    // Initializing and sanitizing //
    FileHandler fileHandler;
    std::filesystem::path writePath{ "./writeFile.txt" };
    std::filesystem::path readPath{ "./readFile.txt" };

    // Trunc deletes contents    
    std::fstream writeFile{ writePath, std::ios_base::trunc }; 
    std::fstream readFile{ readPath, std::ios_base::out };
    
    // Test 1 : Reading
    std::cout << "test 1 : reading the " << readPath << ':' << std::endl;
    std::stringstream buffer;
    
    fileHandler.read("./readFile.txt", buffer);
    if( fileHandler.currentState == States::readError )
    {
        std::cerr << "Could NOT read the file readFile.txt\n";
    }
    else
    {
        std::cout << "Successfully read the file, check it\n";
    }
    std::cout << buffer.rdbuf() << std::endl;

    // Test 2 : Writing

    std::cout << "test 2 : writing to " << readPath << std::endl;
    fileHandler.write( buffer.str(), "./writeFile.txt" );

    if( fileHandler.currentState == States::writeError )
    {
        std::cout << "there was a problem with writing to ./writeFile.txt";
    }
    else 
    {
        std::cout << buffer.rdbuf();
        std::cout << "Successfully wrote the file, check it\n";
    }

    return 0;
}
