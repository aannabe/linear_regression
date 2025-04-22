# Compiler
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++23 -O2

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN = linreg

# Source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# Object files
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SOURCES))

# Default target
all: $(BIN)

# Create the binary
$(BIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files into object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR) $(BIN)

# Run your program
run: $(BIN)
	./$(BIN)

