# Makefile
# Include -g flag to get debugging information
# Needed for gdb and valgrind
all: test
CXXFLAGS = -g --std=c++20

test: iterators.cpp
	g++  ${CXXFLAGS} iterators.cpp -o test

clean:
	rm test
