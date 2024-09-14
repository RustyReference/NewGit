#include "../src/filehandler.h"
#include <iostream>

int main()
{
    FileHandler fileHandler;
    std::stringstream buff;
    fileHandler.read("./textFiles/readFile.txt", buff);
    fileHandler.write("./textFiles/writeFile.txt", buff.str());
    return 0;
}
