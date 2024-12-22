# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include

CXXFLAGS += -I$(INCLUDE_DIR)
LDFLAGS += -lsfml-graphics -lsfml-window -lsfml-system

# Target file
TARGET = $(BIN_DIR)/main
# Source and object files found and defined by iteration
SOURCES = $(shell find $(SRC_DIR) -type f -name '*.cpp')
OBJECTS = $(patsubst $(SRC_DIR)/%, $(BUILD_DIR)/%, $(SOURCES:.cpp=.o))

# Compiler and flags
CXX = g++
CXXFLAGS += -std=c++17 -Wall -Wextra

# Primary build
all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	@$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Cleanup build
clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)

# Start application
run: all
	@$(TARGET)

# Phony targets
.PHONY: all clean run
