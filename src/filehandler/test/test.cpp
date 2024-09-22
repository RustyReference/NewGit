#include "../src/filehandler.h"
#include <iostream>

using namespace std::filesystem;
void testRead( path readPath );
void testWrite( path writePath );

std::string prompt // For testing fileHandler.write function.
{
    "#include <iostream>\n"
    "int main(){\n"
    "   std::cout << \"hello, world\" << std::endl;\n"
    "}\n"
};

int main(int argc, char *argv[])
{
    // Get canonical paths for testing. Not necessary in normal use.
    path testPath{ canonical(argv[0]).parent_path() };
    
    path readPath{ testPath };
    readPath.append("textFiles/readFile.txt");
    
    path writePath{ testPath };
    writePath.append("textFiles/writeFile.txt");
    
    // Test
    testRead(readPath);
    std::cout << "\n\n";
    testWrite(writePath);

    return 0;
}

// Works if correctly reads from readPath to stdout
void testRead( path readPath )
{
    std::stringstream buff;
    if( !FH::read(readPath, buff) )
    {
        std::cerr << "Could not read from " << readPath << '\n';
        return;
    }
    std::cout << readPath << " : \n" << buff.str();
}


// Works if "prompt" is written to writePath despite spaces etc.
void testWrite( path writePath )
{
    if( !FH::write(writePath, prompt) )
    {
        std::cerr << "Could not write to " << writePath << '\n';
        return;
    }
    std::cout << writePath << " : \n";
    std::cout << prompt << std::endl;
}
