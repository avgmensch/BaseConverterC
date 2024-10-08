# Filenames
MAKEFILE = Makefile
EXECUTABLE = cv

# Compiler and linker
CC = gcc
CFLAGS = -Wall -Wextra -Os
LD = gcc
LDFLAGS = -s -lm

# Code formatter
FMT = astyle
FMT_FLAGS = --style=allman --max-code-length=100 --suffix=none

# Define direcories
INC_DIR = include/
SRC_DIR = source/
OBJ_DIR = .build/

# Add get source files and include flag
INC_FILES = $(wildcard $(INC_DIR)*.h)
SRC_FILES = $(wildcard $(SRC_DIR)*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_FILES))
CFLAGS += -I$(INC_DIR)

# Compile executable
bin: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	$(LD) $(LDFLAGS) -o $@ $^

-include $(wildcard $(OBJ_DIR)*.d)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(MAKEFILE) | $(OBJ_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $@

# Phony rules
run: $(EXECUTABLE)
	@./$<

format:
	$(FMT) $(FMT_FLAGS) $(INC_FILES) $(SRC_FILES)

clean:
	rm -vrf $(OBJ_DIR)
	rm -vf $(EXECUTABLE)

.PHONY: run format clean