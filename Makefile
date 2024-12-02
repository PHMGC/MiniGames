# Project name
PRJ = minigames

# Directories
SRC_DIR = src
BUILD_DIR = build
EXTERNALS_DIR = externals

# Target
TARGET = $(BUILD_DIR)/$(PRJ)

# SFML
SFML_DIR = $(EXTERNALS_DIR)/SFML-2.6.2

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Objects
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I$(SFML_DIR)/include
LDFLAGS = -L$(SFML_DIR)/lib -lsfml-graphics -lsfml-window -lsfml-system

# Primary build
all: $(TARGET) sfml_dlls

# Rule to create the executable
$(TARGET): $(OBJS)
	@mkdir -p $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS)

# Rule to build object files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Copy SFML DLLs
sfml_dlls:
	@mkdir -p $(BUILD_DIR)
	@cp $(SFML_DIR)/bin/*.dll $(BUILD_DIR)/

# Start application
start: all
	@$(TARGET)

# Cleanup the build dir
clean:
	@rm -rf $(BUILD_DIR)


# Phony targets
.PHONY: clean sfml_dlls start
