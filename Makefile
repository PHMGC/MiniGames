# Directories
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include
EXTERNALS_DIR = externals

# SFML local files only for Windows 
ifeq ($(OS),Windows_NT)
    SFML_DIR = $(EXTERNALS_DIR)/SFML-2.6.2
    CXXFLAGS += -I$(INCLUDE_DIR) -I$(SFML_DIR)/include
    LDFLAGS += -L$(SFML_DIR)/lib -lsfml-graphics -lsfml-window -lsfml-system
    COPY_DLLS = @mkdir -p $(BIN_DIR) && cp $(SFML_DIR)/bin/*.dll $(BIN_DIR)/
else
# Checking if SFML is installed on system
    SFML_CHECK := $(shell pkg-config --exists sfml-graphics sfml-window sfml-system || echo "missing")
    ifeq ($(SFML_CHECK),missing)
        $(error SFML is not installed in your system. Please install SFML before continuing.)
    endif
    CXXFLAGS += -I$(INCLUDE_DIR)
    LDFLAGS += -lsfml-graphics -lsfml-window -lsfml-system
    COPY_DLLS = @ # No need, cause
endif

# Source and object files
TARGET = $(BIN_DIR)/main
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)
OBJECTS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# Compiler and flags
CXX = g++
CXXFLAGS += -std=c++17 -Wall -Wextra

# Primary build
all: $(TARGET) copy_dlls

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	@$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# SFML dependencies
copy_dlls:
	$(COPY_DLLS)

# Cleanup build
clean:
	@rm -rf $(BUILD_DIR) $(BIN_DIR)

# Start application
run: all
	@$(TARGET)

# Phony targets
.PHONY: all clean run copy_dlls
