#include "filehandler.h"
#include <iostream>

int main()
{
    FileHandler fileHandler = FileHandler();
    std::stringstream BUFFER;
    fileHandler.read("./filehandler.cpp", BUFFER);
    
    std::string temp;
    while(BUFFER >> temp)
    {
        std::cout << temp << std::endl;
    }

    return 0;
}
