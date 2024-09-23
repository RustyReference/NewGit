#include "../src/filehandler.h"
#include <iostream>
#include <cassert>

using namespace std::filesystem;
void testRead( path readPath );
void testWrite( path writePath );
void testAppend( path appendPath );
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
    path mkdirpPath{ "testOut/newdir2" };
    path filePath{ "testOut/file.txt" };

    // Test
    testMkdirp(mkdirpPath);
    testWrite(filePath);

    // Append is special
    testAppend(filePath);
    testAppend(filePath);
    testAppend(filePath);
    
    // Read the file to stdout
    std::cout << "\n\n";
    testRead(filePath);
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
        std::cerr << "Could not write to\t" << writePath << '\n';
    }
}

// Works if "newdir/newdir2" is made 
void testMkdirp( path folderPath )
{
    if( !FH::mkdirp( folderPath ) )
    {
        std::cerr << "Could not make folder\t" << folderPath << '\n';
    }    
}

// Works if "appended" is appended to appendPath.
void testAppend( path appendPath )
{
    if( !FH::append(appendPath, "appended\n") )
    {
        std::cerr << "Could not append :(\t" << appendPath << '\n';
    }
}
