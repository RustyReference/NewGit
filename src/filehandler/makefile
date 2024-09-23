CC=g++ --std=c++23
CFLAGS= -Wall -Wextra -Weffc++ -Wno-sign-conversion -Werror
SRC = ./src/filehandler.cpp
OBJ = ./filehandler.o
TESTPATH = ./test
TESTSRC = test.cpp
TESTOUT = test

test: buildHandler buildTest
	./$(TESTPATH)/$(TESTOUT)

buildHandler: 
	$(CC) $(CFLAGS) -c $(SRC) -o $(OBJ)

buildTest:
	$(CC) $(CFLAGS) $(OBJ) $(TESTPATH)/$(TESTSRC) -o $(TESTPATH)/$(TESTOUT)

clean:
	rm -rf ./testOut
	rm ./filehandler.o
	rm ./test/test
