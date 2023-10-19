# Specifying the compiler to be used (clang++-14) and the C++ version (C++20 or later)
CXX=clang++-14
CXXVERSION=c++2a

# Defining paths for sources and object files
SOURCE_PATH=sources
OBJECT_PATH=objects

# Compiler flags specifying the C++ version, turning all warnings into errors, and including the source path
CXXFLAGS=-std=$(CXXVERSION) -Werror -Wsign-conversion -I$(SOURCE_PATH)

# clang-tidy flags for static code analysis, specifying checks to be performed and treating warnings as errors
TIDY_FLAGS=-extra-arg=-std=$(CXXVERSION) -checks=bugprone-*,clang-analyzer-*,cppcoreguidelines-*,performance-*,portability-*,readability-*,-cppcoreguidelines-pro-bounds-pointer-arithmetic,-cppcoreguidelines-owning-memory --warnings-as-errors=*

# Valgrind flags for dynamic code analysis (memory leak detection), specifying the details to be reported
VALGRIND_FLAGS=-v --leak-check=full --show-leak-kinds=all  --error-exitcode=99

# Automatically setting variables based on file paths and extensions
SOURCES=$(wildcard $(SOURCE_PATH)/*.cpp)
HEADERS=$(wildcard $(SOURCE_PATH)/*.hpp)
OBJECTS=$(subst sources/,objects/,$(subst .cpp,.o,$(SOURCES)))

# Rule for running the demo executable
run: demo
	./$^

# Rule for building the demo executable, linking object files together
demo: Demo.o $(OBJECTS) 
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule for building the test executable, linking object files together
test: TestCounter.o Test.o $(OBJECTS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule for running clang-tidy for static code analysis
tidy:
	clang-tidy $(HEADERS) $(TIDY_FLAGS) --

# Rule for running valgrind for dynamic code analysis (memory leak detection)
valgrind: demo test
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./demo 2>&1 | { egrep "lost| at " || true; }
	valgrind --tool=memcheck $(VALGRIND_FLAGS) ./test 2>&1 | { egrep "lost| at " || true; }

# Rule for compiling individual object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

# Rule for compiling object files from the sources directory to the objects directory
$(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) --compile $< -o $@

# Rule for cleaning up the project by removing object files and executables
clean:
	rm -f $(OBJECTS) *.o test* demo*
	rm -f StudentTest*.cpp
