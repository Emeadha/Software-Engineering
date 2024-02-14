# Makefile for simulation
# To use: "make all" to compile or "make clean" to remove excutables

# Compiler and flags
CXX = g++
# Specify c++
CXXFLAGS = -std=c++11

# Our Source files
SRC_FILES = airport.cpp clock.cpp main.cpp passenger.cpp plane.cpp timeManager.cpp airline.cpp gate.cpp flight.cpp

# Our Header files
HEADER_FILES = airport.h clock.h passenger.h plane.h timeManager.h timeObserver.h airline.h gate.h flight.h

# Object files to be made
OBJ_FILES = $(SRC_FILES:.cpp=.o)

# Target executable
TARGET = airline_simulation

# Build rule
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ_FILES)

# Object file rule
%.o: %.cpp $(HEADER_FILES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# When we want to run clean
clean:
	rm -f $(TARGET) $(OBJ_FILES)

