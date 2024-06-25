# Executable Name
EXENAME = finalproj
TEST = test

# Object Types
OBJS = readFromFile.o main.o Vertex.o Dijkstras.o BFS.o AStar.o
OBJS_TEST = catchmain.o readFromFile.o Vertex.o Dijkstras.o BFS.o AStar.o tests.o
CATCH = catch

# Compilation Flags
CXX = clang++
CXXFLAGS = $(CS225) -std=c++14 -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++14 -stdlib=libc++ -lc++abi -lm

# Custom Clang Enforcement
include make/customClangEnforcement.mk

# Define Makefile Rules
.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

catchmain.o: catch/catchmain.cpp
	$(CXX) $(CXXFLAGS) catch/catchmain.cpp

readFromFile.o: readFromFile.cpp
	$(CXX) $(CXXFLAGS) readFromFile.cpp

Vertex.o: Vertex.cpp
	$(CXX) $(CXXFLAGS) Vertex.cpp

Dijkstras.o: Dijkstras.cpp
	$(CXX) $(CXXFLAGS) Dijkstras.cpp

BFS.o: BFS.cpp
	$(CXX) $(CXXFLAGS) BFS.cpp

AStar.o: AStar.cpp
	$(CXX) $(CXXFLAGS) AStar.cpp

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

tests.o: Tests/tests.cpp
	$(CXX) $(CXXFLAGS) Tests/tests.cpp

$(TEST): output_msg $(OBJS_TEST)
	$(LD) $(OBJS_TEST) $(LDFLAGS) -o $(TEST)

clean:
	-rm -f *.o $(EXENAME) $(TEST)