# Compiler to use
CXX = g++

# Compiler flags
CXXFLAGS = `fltk-config --cxxflags` -std=c++11 # Assuming you're using at least C++11

# Linker flags
LDFLAGS = `fltk-config --ldflags`

# Executable name
EXECUTABLE = basic_fltk_app

# Source files
SOURCES = main.cpp tasks.cpp 

# Object files (automatically generated from SOURCES)
OBJECTS = $(SOURCES:.cpp=.o)

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $(EXECUTABLE)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(EXECUTABLE)

run: $(EXECUTABLE)
	./$(EXECUTABLE)