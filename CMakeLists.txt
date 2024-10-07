cmake_minimum_required( VERSION 3.30.4 )

set( CMAKE_CXX_STANDARD 20 )
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

set( SRCFILES 
    ./src/logger/filehandler/src/filehandler.cpp 
    ./src/logger/logger.cpp 
    ./src/main.cpp 
)

project( NewGit )
add_executable( NewGit ${SRCFILES} )
