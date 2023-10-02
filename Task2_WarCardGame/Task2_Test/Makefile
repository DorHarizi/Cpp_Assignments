#!make -f

# Compiler and Compilation Flags
CXX=clang++-14
CXXVERSION=c++2a
SOURCE_PATH=sources
OBJECT_PATH=objects
CXXFLAGS=-std=$(CXXVERSION) -Werror -Wsign-conversion -I$(SOURCE_PATH)
TIDY_FLAGS=-extra-arg=-std=$(CXXVERSION) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=*
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all --error-exitcode=99

# Define Source Files, Headers, and Objects
SOURCES=$(wildcard $(SOURCE_PATH)/*.cpp)
HEADERS=$(wildcard $(SOURCE_PATH)/*.hpp)
OBJECTS=$(subst sources/,objects/,$(subst .cpp,.o,$(SOURCES)))

# Targets

# Build the 'demo' target, linking Demo.o and OBJECTS
demo: Demo.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Build the 'test1' target, linking TestRunner.o, StudentTest1.o, and OBJECTS
test1: TestRunner.o StudentTest1.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Run clang-tidy on the source code files with specified checks and options
tidy:
	clang-tidy $(HEADERS) $(TIDY_FLAGS) --

# Run valgrind on the 'test1' target with specified memory-checking options
valgrind: test1
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test1 2>&1 | { egrep "lost| at " || true; }

# Compile a source file into an object file
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

# Compile a source file in a specified path into an object file in a specified path
$(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

# Clean up object files and target executables
clean:
	rm -f $(OBJECTS) *.o test* demo*
