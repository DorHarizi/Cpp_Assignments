# Specify the default compiler as gcc
CXX=gcc

# Compiler flags: Wall (enable all warnings) and g (include debugging information)
CXXFLAGS= -Wall -g

# List of header files
HEADERS=AdptArray.h book.h Person.h

# List of object files to be generated
OBJECTS=AdptArray.o book.o Person.o

# List of source files
SOURCES=AdptArray.c book.c Person.c

# Target for running the 'demo' program
run: demo
	./$^

# Target for running 'valgrind' memory tests on 'demo'
mem_test: demo
	valgrind ./$^

# Target to build the 'demo' executable, depends on 'Demo.o' and 'OBJECTS'
demo: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o demo

# Rule to compile any '.o' file from its corresponding '.c' source file
%.o: %.c $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

# Clean up target to remove object files and the 'demo' executable
clean:
	rm -f *.o demo
