# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I$(INCLUDE_DIR)
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Target file
TARGET = $(BIN_DIR)/main

# Source and object files
SUBDIRS := $(wildcard $(SRC_DIR)/*)
SOURCES := $(wildcard $(SRC_DIR)/*.cpp) $(foreach dir, $(SUBDIRS), $(wildcard $(dir)/*.cpp))

# Map source files to object files
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# Primary build
all: $(TARGET)

$(TARGET): $(OBJECTS)
	mkdir -p $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Cleanup build
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Start application
run: all
	$(TARGET)

# Phony targets
.PHONY: all clean run
