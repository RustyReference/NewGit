#include "../src/filehandler.h"
#include <iostream>

int main()
{
    FileHandler fileHandler;
    std::stringstream buff;
    fileHandler.read("./textFiles/readFile.txt", buff);
    std::cout << buff.str();
    fileHandler.write();
    return 0;
}
