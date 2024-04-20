# Compilation variables
CC = gcc
CPPFLAGS = 
CFLAGS = -Wall -Wextra -Werror -O2 -lncurses -lm
DEBUG_FLAGS = -g 
TARGET = mysh

# Output directories
BIN_DIR = bin

# Directory for object creation
SRC_DIR = src
OBJ_DIR = build

# Source and object files
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Add a rule to create the bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Modify the rule for creating the executable to place it in the bin directory
$(BIN_DIR)/$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CC) $(CPPFLAGS) -o $@ $^ $(CFLAGS)

# Rule to compile objects
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) -o $@ -c $< $(CFLAGS)

# Create the build directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Add dependency for the executable
all: $(BIN_DIR)/$(TARGET)

# Rule for cleaning object directories and executables
clean:
	rm -f $(OBJ_DIR)/*.o
	rm -f $(BIN_DIR)/$(TARGET)

# Rule for full cleaning of object files and executable
fullclean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Rules to execute the executable
exec:
	./$(BIN_DIR)/$(TARGET)

# Rule to run the executable with valgrind
valgrind:
	valgrind --leak-check=full --show-leak-kinds=all ./$(BIN_DIR)/$(TARGET)


# Special variables
# $@ target name
# $< first dependency name
# $^ list of dependencies
# $? list of dependencies newer than the target
# $* file name without its extension
