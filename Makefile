# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++23 -O2

# Directories
SRC_DIR = src
OBJ_DIR = obj
BIN = linreg

# File lists
CPP_FILES := $(wildcard $(SRC_DIR)/*.cpp)
HEADERS := $(wildcard $(SRC_DIR)/*.h)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(CPP_FILES))

# Default target
all: $(BIN)

# Link object files into final binary
$(BIN): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp files into .o, rebuild if .cpp or any .h changes
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build files
clean:
	rm -rf $(OBJ_DIR) $(BIN)

# Run the program
run: $(BIN)
	./$(BIN)

# Avoid confusion if one makes files with below names
.PHONY: all clean run
