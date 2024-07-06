# Compiler and flags
CC = gcc
INCLUDE_FLAGS = -I./include

# Directories
SOURCE_DIR = src
OBJECT_DIR = bin
BUILD_DIR = build

# Source files and object files
SOURCES = $(wildcard $(SOURCE_DIR)/*.c)
OBJECTS = $(patsubst $(SOURCE_DIR)/%.c, $(OBJECT_DIR)/%.o, $(SOURCES))

# Target executable
EXECUTABLE = $(BUILD_DIR)/app

# Default target
all: $(EXECUTABLE)

# Compile source files into object files
$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.c
	@mkdir -p $(OBJECT_DIR)
	$(CC) $(INCLUDE_FLAGS) -c $< -o $@

# Link the target executable
$(EXECUTABLE): $(OBJECTS)
	@mkdir -p $(dir $(EXECUTABLE))
	$(CC) $^ -o $@

# Clean up
.PHONY: clean
clean:
	rm -rf $(OBJECT_DIR)/*.o $(EXECUTABLE)

