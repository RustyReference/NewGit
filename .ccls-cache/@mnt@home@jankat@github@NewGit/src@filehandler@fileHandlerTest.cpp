#include "filehandler.h"
#include <iostream>

int main()
{
    FileHandler fileHandler = FileHandler();
    std::stringstream BUFFER;
    fileHandler.readFile("./filehandler.cpp", BUFFER);
    
    std::string temp;
    while(BUFFER >> temp)
    {
        std::cout << temp << std::endl;
        std::cout << "hello, world" << std::endl;
    }

    return 0;
}
