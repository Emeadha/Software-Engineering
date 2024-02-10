# Makefile

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11

# Source files
SRC_FILES = airport.cpp clock.cpp main.cpp passenger.cpp plane.cpp timeManager.cpp airline.cpp gate.cpp flight.cpp

# Header files
HEADER_FILES = airport.h clock.h passenger.h plane.h timeManager.h timeObserver.h airline.h gate.h flight.h

# Object files
OBJ_FILES = $(SRC_FILES:.cpp=.o)

# Target executable
TARGET = airline_simulation

# Build rule
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJ_FILES)

# Object file rule
%.o: %.cpp $(HEADER_FILES)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(TARGET) $(OBJ_FILES)

