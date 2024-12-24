# Diretórios
SRC_DIR = src
BUILD_DIR = build
BIN_DIR = bin
INCLUDE_DIR = include

# Compilador e flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -I$(INCLUDE_DIR) -DSFML_STATIC
LDFLAGS = -L./lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s

UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
    LDFLAGS += -lGL -lfreetype -lflac -lvorbisenc -lvorbisfile -lvorbis -logg -lpthread
else ifeq ($(OS),Windows_NT)
    LDFLAGS += -lfreetype -lopengl32 -lgdi32 -lwinmm -lflac -lvorbisenc -lvorbisfile -lvorbis -logg -lkernel32 -luser32
endif


# Arquivo alvo
TARGET = $(BIN_DIR)/main

# Fontes e objetos
SUBDIRS := $(wildcard $(SRC_DIR)/*)
SOURCES := $(wildcard $(SRC_DIR)/*.cpp) $(foreach dir, $(SUBDIRS), $(wildcard $(dir)/*.cpp))
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# Construção principal
all: $(TARGET)

$(TARGET): $(OBJECTS)
	mkdir -p $(BIN_DIR)
	$(CXX) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpar
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

# Executar
run: all
	$(TARGET)

# Phony
.PHONY: all clean run
