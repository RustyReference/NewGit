#include "../src/filehandler.h"
#include <iostream>
#include <cassert>

using namespace std::filesystem;
void testRead( path readPath );
void testWrite( path writePath );
void testMkdirp( path mkdirpPath );

std::string prompt // For testing fileHandler.write function.
{
    "#include <iostream>\n"
    "int main(){\n"
    "   std::cout << \"hello, world\" << std::endl;\n"
    "}\n"
};

int main()
{
    // Get canonical paths for testing. Not necessary in normal use. 
    path readPath{ "./textFiles/readFile.txt" };
    
    path writePath{ "./textFiles/writeFile.txt" };

    path mkdirpPath{ "newdir/newdir2" };
    
    // Test
    testRead(readPath);
    testWrite(writePath);
    testMkdirp(mkdirpPath);

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
    }
}

// Works if "newdir/newdir2" is made 
void testMkdirp( path folderPath )
{
    if( FH::mkdirp( folderPath ) )
    {
        std::cerr << "Could not make folder" << folderPath << '\n';
    }    
}
