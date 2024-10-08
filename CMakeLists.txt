cmake_minimum_required( VERSION 3.30.4 )

set( CMAKE_CXX_STANDARD 23 )
set( CMAKE_CXX_STANDARD_REQUIRED ON )
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

set( SRCFILES 
    ./src/logger/filehandler/filehandler.cpp
    ./src/logger/logger.cpp
    ./src/main.cpp
)

project( NewGit CXX)
add_executable( NewGit ${SRCFILES} )
